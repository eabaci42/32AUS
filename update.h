#ifndef UPDATE_H
#define UPDATE_H

#include <Arduino.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class UpdateHandler {
  public:
    UpdateHandler(const char* password); // Yapıcı yöntem
    void beginOTA();
    void handleOTA();
  private:
    const char* _otaPassword; // OTA şifre bilgisi
};

#endif
