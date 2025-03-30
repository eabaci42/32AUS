#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class BuzzerControl
{
public:
    BuzzerControl(int buzzerPin);
    void buzzer_high();
    void buzzer_low();

private:
    int _buzzerPin;
};
#endif
