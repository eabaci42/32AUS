#ifndef PANICB_H
#define PANICB_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "../communication/mail.h"
#include "../interfaces/led.h"

class MobileButton
{
public:
    MobileButton(int port, int red, int green, int blue);
    bool connect();
    bool fetch_data();
    bool get_location();
    DynamicJsonDocument clean_data();
    bool parse_data();
    bool send_mobile_mail();
    void help_me_mobile();

private:
    String _jdata;
    String _apiUrl;
    String _apiKey;
    String _apiHost;
    String _message;
    int _redPin;
    int _greenPin;
    int _bluePin;
    int _port;
};

class HomeButton
{
public:
    HomeButton(int red, int green, int blue);
    void help_me_home();
    bool send_home_mail();

private:
    String _message;
    int _redPin;
    int _greenPin;
    int _bluePin;
};

#endif
