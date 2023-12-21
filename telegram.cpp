#include "telegram.h"
#define BOT_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
WiFiClientSecure client;
HeatHum dht(3);

#ifdef ESP8266
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

UniversalTelegramBot bot(BOT_TOKEN, client);

TelegramBot::TelegramBot(const String userIds[], int usercount)
{

  _userCount = usercount;
  for (int i = 0; i < _userCount; i++)
  {
    _userIds[i] = userIds[i];
  }
}

void TelegramBot::vercert()
{
  client.setTrustAnchors(&cert);
#ifdef ESP32
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
#endif
}

void TelegramBot::telegram_update()
{
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  if (numNewMessages)
  {
    Serial.println("Mesajın alındı");
    handleNewMessages(numNewMessages);
  }
}

bool TelegramBot::checkTelegramId(String id)
{
  for (int i = 0; i < _userCount; i++)
  {
    Serial.println("Comparing with: " + _userIds[i]);
    if (id == _userIds[i])
    {
      Serial.println("ID matched user: " + id);
      return true;
    }
  }
  Serial.println("ID did not match any user.");
  return false;
}

void TelegramBot::sendBroadcast(String message)
{
  for (int i = 0; i < _userCount; i++)
  {
    bot.sendMessage(_userIds[i], message, "");
  }
}

void TelegramBot::sendToUser(String userId, String message)
{
  bot.sendMessage(userId, message, "");
}

void TelegramBot::handleNewMessages(int numNewMessages)
{
  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = String(bot.messages[i].chat_id);
    Serial.println("Chat id alındı: " + chat_id);
    String text = bot.messages[i].text;
    Serial.println("Text id alındı: " + text);

    // ID kontrolü
    if (!checkTelegramId(chat_id))
    {
      Serial.println("Kullanıcı bulunamadı");
      // Eğer geçerli bir kullanıcı değilse, cevap verme ve diğer işlemleri atla
      bot.sendMessage(chat_id, "Yetkisiz Kullanıcı", "");
      continue;
    }

    if (text == "/start")
    {
      String message = handleStartCommand(chat_id, bot.messages[i].from_name);
      dht.begin();
      bot.sendMessage(chat_id, message, "");
    }
    else if (text == "/status")
    {
      String message = checkStatus();
      bot.sendMessage(chat_id, message, "");
    }
    else if (text == "/heat")
    {
      String message = checkHeat();
      bot.sendMessage(chat_id, message, "");
    }
    else if (text == "/humidity")
    {
      String message = checkHumidity();
      bot.sendMessage(chat_id, message, "");
    }
    else if (text == "/heathum")
    {
      String message = checkHeatHum();
      bot.sendMessage(chat_id, message, "");
    }
    // Diğer komutları buraya ekleyebilirsiniz
  }
}

String TelegramBot::handleStartCommand(String chat_id, String first_name)
{
  String message = "Merhaba " + first_name + ", size nasıl yardımcı olabilirim?\n\n";
  message += "İşte kullanabileceğiniz komutlar:\n";
  message += "/status - Tüm sensörlerin durumunu kontrol eder.\n";
  message += "/heat - Sıcaklık değerini gönderir.\n";
  message += "/humidity - Nem değerini gönderir.\n";
  message += "/heathum - Sıcaklık ve nem değerlerini gönderir.\n";

  return message;
}

String TelegramBot::checkStatus()
{
  String statusMessage = "";

  statusMessage.concat("Sıcaklık ve Nem durumu: ");
  statusMessage.concat(checkHeatHum());
  statusMessage.concat("\n");

  return statusMessage;
}

String TelegramBot::checkHeat()
{
  float heat = dht.readTemperature();

  return ("Sıcaklık: " + String(heat) + " derece\n");
}

String TelegramBot::checkHumidity()
{
  float heat = dht.readHumidity();
  return ("Nem: %" + String(heat) + " seviyesindedir.\n");
}

String TelegramBot::checkHeatHum()
{
  return (checkHeat() + checkHumidity);
}

bool TelegramBot::alarm_message(String message)
{
  sendBroadcast(message);
  return true;
}
