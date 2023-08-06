#include "other.h"

OtherFunctions::OtherFunctions(String ssid, String password) /* other kütüphanesi yapıcı methodum*/
{
  _wifi_ssid = ssid;
  _wifi_password = password;
}

void OtherFunctions::wifi_connect() /* wifi bağlantısını sağlayan fonksiyon */
{
  WiFi.begin(_wifi_ssid.c_str(), _wifi_password.c_str());
  Serial.println("\nConnecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(150);
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());
}

/*
void OtherFunctions::wifi_connect()
{
  char ssid[_wifi_ssid.length() + 1];
  char password[_wifi_password.length() + 1];
  _wifi_ssid.toCharArray(ssid, _wifi_ssid.length() + 1);
  _wifi_password.toCharArray(password, _wifi_password.length() + 1);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(150);
  }
  Serial.println("\nConnected to WiFi");
}
*/