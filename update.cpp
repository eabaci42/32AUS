#include "update.h"
#include <ArduinoOTA.h>

UpdateHandler::UpdateHandler(const char* password) {
  _otaPassword = password;
}

void UpdateHandler::beginOTA() {
#if defined(ESP8266)
  Serial.begin(115200);
  Serial.println("Başlatılıyor");
  Serial.print("IP Adresiniz: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else
      type = "filesystem";

    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Hata[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Yetki Hatası");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Baslatma Basarisiz");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Baglanti Basarisiz");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Veri Alinamadi");
    else if (error == OTA_END_ERROR) Serial.println("Sonlandirma Basarisiz");
  });

  ArduinoOTA.setPassword(_otaPassword); // OTA şifresini belirle

  ArduinoOTA.begin();

#elif defined(ESP32)
  Serial.begin(115200);
  Serial.println("Başlatılıyor");
  Serial.print("IP Adresiniz: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.onStart([](ota_error_t error) {
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Yetki Hatası");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Baslatma Basarisiz");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Baglanti Basarisiz");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Veri Alinamadi");
    } else if (error == OTA_END_ERROR) {
      Serial.println("Sonlandirma Basarisiz");
    }
  });

  ArduinoOTA.setPassword(_otaPassword); // OTA şifresini belirle

  ArduinoOTA.begin();
#endif
}

void UpdateHandler::handleOTA() {
  ArduinoOTA.handle();
}
