#include "fire.h"
#include "telegram.h"

FireGasSmoke::FireGasSmoke(int flamePin, int smokePin, int gasPin, int buzzer, int red, int green, int blue, const String userIds[], int usercount) /* Yangın kütüphanesi yapıcı methotu*/
{
  _flamePin = flamePin;
  _smokePin = smokePin;
  _gasPin = gasPin;
  _buzzer = buzzer;
  _redPin = red;
  _greenPin = green;
  _bluePin = blue;
  _userCount = usercount;
  for (int i = 0; i < _userCount; i++)
  {
    _userIds[i] = userIds[i];
  }
  pinMode(_flamePin, INPUT);
  pinMode(_smokePin, INPUT);
  pinMode(_gasPin, INPUT);
}

bool FireGasSmoke::flame_sensor() /* Alev sensörü konrolü*/
{
  Serial.println("Alev sensörü ölçüm yapıyor...");
  if (digitalRead(_flamePin) == LOW)
    return true;
  else
    return false;
}

bool FireGasSmoke::gas_sensor() /* Dijital gaz sensörü konrolü*/
{
  Serial.println("Dijital gaz sensörü ölçüm yapıyor...");
  if (digitalRead(_gasPin) == LOW)
    return true;
  else
    return false;
}

bool FireGasSmoke::smoke_sensor() /* Analog gaz sensörü konrolü*/
{
  Serial.println("Analog gaz sensörü ölçüm yapıyor...");
  int smoke;
  smoke = analogRead(_smokePin);
  if (smoke > 2000)
  {
    Serial.println("\nOkunan gaz seviyesi kritik düzeyin üzerinde.\nOkuma: " + String(smoke));
    return true;
  }
  else
    return false;
}

void FireGasSmoke::check() /* Bütün kontrollerin yapıldığı ve afet durumunun karar alındığı fonksiyon*/
{
  BuzzerControl buzzer(_buzzer);
  LedControl led(_redPin, _greenPin, _bluePin, 300, 7);
  bool controlmail;
  bool controltelegram;
  bool flamecheck;
  bool gascheck;

  flamecheck = false;
  gascheck = false;
  controlmail = false;
  controltelegram = false;
  if (flame_sensor() == true)
    flamecheck = true;
  else
    flamecheck = false;

  if (gas_sensor() == true)
  {
    if (smoke_sensor() == true)
    {
      gascheck = true;
    }
    else
      gascheck = false;
  }
  else
    gascheck = false;

  if (flamecheck == true && gascheck == true)
  {
    _message.clear();
    _message = "\nEv içerisinde yangın durumu tespit ettik. Ateş ve duman sensörleri onayladı.\n";
    _color.clear();
    _color = "fire";
    controlmail = true;
    controltelegram = true;
  }
  else if (flamecheck == true)
  {
    _message.clear();
    _message = "\n Evinizde ateş tespit edildi!\nHerhangi bir cismin tutuşmasi söz konusu olabilir. Alev sensörü onayladı.\n";
    _color.clear();
    _color = "fire";
    controlmail = true;
    controltelegram = true;
  }
  else if (gascheck == true)
  {
    _message.clear();
    _message = "\nEv içerisinde yanıcı gaz veya duman durumu tespit ettik. Duman sensörleri onayladı.\n";
    _color.clear();
    _color = "smoke";
    controlmail = true;
    controltelegram = true;
  }
  else
    controlmail = false;
  controltelegram = false;

  if (controlmail == true && controltelegram == true)
  {
    led.error(_color);
    buzzer.buzzer_high();
    while (controlmail == true || controltelegram == true)
    {
      if (controlmail == true)
      {
        controlmail = !mail_notification();
      }
      if (controltelegram == true)
      {
        controltelegram = !telegram_notification();
      }
    }
  }
  else
  {
    led.off();
    buzzer.buzzer_low();
  }
}

bool FireGasSmoke::mail_notification() /* Mail kütüphanesine gerekli bilgileri gönderen ve mail gönderimini sağlayan fonksiyon*/
{
  MailSender fire("Fire and Gas Sensor", "Yangın Birimi Bildirimi!", "Yangın veya Duman Durum Bildirimi!", _message, "Acil Durum Merkezi!", "ertugrul.sunum@gmail.com");
  if (fire.send_email() == true)
    return true;
  else
    return false;
}
/*
bool FireGasSmoke::telegram_notification() 
{
  TelegramBot alarm(_userIds, _userCount);
  if (alarm.alarm_message(_message) == true)
    return true;
  else
    return false;
}
*/
