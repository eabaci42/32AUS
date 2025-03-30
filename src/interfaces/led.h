#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <analogWrite.h>

/*
0 Değeri 0 iken
255 Değeri 1'dir
*/

class LedControl
{
public:
    LedControl(int redPin, int greenPin, int bluePin, int time, int replay);
    void on(String colorCode);
    void off();
    void error(String color);
    void rgb_convert(String colorCode);
    void strobing(String colorCode);
    // void color_cycle(int delay_time);

private:
    int _redPin;
    int _greenPin;
    int _bluePin;
    int _time;
    int _replay;
};

#endif
