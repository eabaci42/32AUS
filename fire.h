#ifndef FIRE_H
#define FIRE_H

#include <Arduino.h>
#include "mail.h"
#include "buzzer.h"
#include "led.h"

class FireGasSmoke
{
public:
    FireGasSmoke(int flamePin, int smokePin, int gasPin, int buzzer, int red, int green, int blue, const String userIds[], int usercount);
    void check();
    bool flame_sensor();
    bool gas_sensor();
    bool smoke_sensor();
    bool mail_notification();
    bool telegram_notification();

private:
    int _flamePin;
    int _smokePin;
    int _gasPin;
    int _buzzer;
    int _redPin;
    int _greenPin;
    int _bluePin;
    String _color;
    String _message;
    String _userIds[10];
    int _userCount;
};
#endif
