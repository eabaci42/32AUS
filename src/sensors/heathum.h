#ifndef HeatHum_h
#define HeatHum_h

#include "Arduino.h"
#include <DHT.h>

class HeatHum
{
public:
    HeatHum(int heathumpin);
    void begin();
    float readTemperature();
    float readHumidity();

private:
    int _heathumpin;
};

#endif
