#ifndef FLOOD_H
#define FLOOD_H

#include <Arduino.h>
#include "mail.h"
#include "buzzer.h"
#include "led.h"

class FloodSensor
{
public:
  FloodSensor(int trigPin, int echoPin, int itarator, int time, int buzzer, int red, int green, int blue, const String userIds[], int usercount);
  void get_height();
  bool check_warning();
  float calculate_height();
  bool mail_notification();
  bool telegram_notification();
  void control();

private:
  int _trigPin;
  int _echoPin;
  float _height;
  int _replay;
  int _time;
  int _buzzer;
  int _redPin;
  int _greenPin;
  int _bluePin;
  String _color;
  String _message;
  int _yukseklik;
  String _userIds[10];
  int _userCount;
};

#endif
