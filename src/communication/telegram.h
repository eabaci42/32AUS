#ifndef Telegram_h
#define Telegram_h

#include <Arduino.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "../sensors/heathum.h"

class TelegramBot
{

public:
  TelegramBot(const String userIds[], int usercount);
  void vercert();
  void telegram_update();
  bool checkTelegramId(String id);
  void sendBroadcast(String message);
  void sendToUser(String userId, String message);
  void handleNewMessages(int numNewMessages);
  String handleStartCommand(String chat_id, String first_name);
  String checkStatus();
  String checkHeat();
  String checkHumidity();
  String checkHeatHum();
  bool alarm_message(String message);


private:
  String _userIds[10];
  int _userCount;
};

#endif
