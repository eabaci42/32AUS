#ifndef OTHER_H
#define OTHER_H

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

class OtherFunctions
{
public:
    OtherFunctions(String ssid, String password);
    void wifi_connect();

private:
    String _wifi_ssid;
    String _wifi_password;
};

#endif