#include "heatHum.h"

#define DHTTYPE DHT11

DHT dht(_heathumpin, DHTTYPE);

HeatHum::HeatHum(int heathumpin)
{
    _heathumpin = heathumpin;
}

void HeatHum::begin()
{
    dht.begin();
}

float HeatHum::readTemperature()
{
    float t = dht.readTemperature();
    return t;
}

float HeatHum::readHumidity()
{
    float h = dht.readHumidity();
    return h;
}
