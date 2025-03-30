#include <Arduino.h>
#include "interfaces/buzzer.h"
#include "sensors/fire.h"
#include "sensors/flood.h"
#include "interfaces/led.h"
#include "communication/mail.h"
#include "utils/other.h"
#include "controllers/panicb.h"
#include "communication/telegram.h"
#include "sensors/earthquake.h"
#include "communication/update.h"

int Pins[20] = {36, 23, 18, 5, 3, 15, 19, 13, 12, 14, 34, 17, 16};
const String USER_IDS[1] = {"1472673180"};

/*
int Pins[20] = { 0,  1,  2, 3, 4,  5,  6,  7,  8,  9, 10, 11, 17};*/
/*
---------------------------------------------------------------
*   GPIO * Tür    *   Sensörler       *    Pins  *  Renkler   *
---------------------------------------------------------------
* #GPIO36 analog 	  Gas Sensor            Pins[0]   Sarı      *
* #GPIO23 digital   Flame Sensor          Pins[1]   Turuncu   *
* #GPIO18 digital   Ultrasonik Echo       Pins[2]   Mor       *
* #GPIO5  digital   Ultrasonik Trig       Pins[3]   Yeşil     *
* #GPIO3  digital	  Nem & Sıcaklık DHT11  Pins[4]   Sarı      *
* #GPIO15 digital	  Panic Button Mobile   Pins[5]   Sarı      *
* #GPIO19 digital	  Panic Button Home     Pins[6]   Mavi      *
* #GPIO13 analog	  RGB Diyot Kırmızı     Pins[7]   Direct    *
* #GPIO12 analog	  RGB Diyot Yeşil       Pins[8]   Direct    *
* #GPIO14 analog	  RGB Diyot Mavi        Pins[9]   Direct    *
* #GPIO34 digital 	Gas Sensor            Pins[10]  Yeşil     *
* #GPIO17 digital 	Buzzer                Pins[11]  Sarı      *
* #GPIO16 digital 	ResetFlood            Pins[12]  Sarı      *
* #GPIO21 Data     	    SDA               Pins[13]  Toprak    *
* #GPIO22 Data     	    SCL               Pins[14]  Mavi      *
---------------------------------------------------------------
*/
/* Ana program iskeletim */

bool hcheck = false;

FireGasSmoke firegs(Pins[1], Pins[0], Pins[10], Pins[11], Pins[7], Pins[8], Pins[9], USER_IDS, 1);
FloodSensor flood(Pins[3], Pins[2], 20, 1000, Pins[11], Pins[7], Pins[8], Pins[9], USER_IDS, 1);
OtherFunctions wific("esp32", "esp32wifi");
MobileButton mobil(443, Pins[7], Pins[8], Pins[9]);
HomeButton home(Pins[7], Pins[8], Pins[9]);
TelegramBot telegram(USER_IDS, 1);
Earthquake earthquake(1.0, USER_IDS, 1); // 1.0 g threshold
UpdateHandler updateHandler("flender123");

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  wific.wifi_connect();
#ifdef ESP8266
  configTime(3, 0, "pool.ntp.org");
  telegram.vercert();
#endif
#ifdef ESP32
  configTime(3, 0, "pool.ntp.org", "time.nist.gov", "ntp1.aliyun.com");
  telegram.vercert();
#endif
  while (!earthquake.begin())
    Serial.println("Could not start earthquake detector");
  wific.wifi_connect();
  pinMode(Pins[5], INPUT);
  pinMode(Pins[6], INPUT);
  pinMode(Pins[12], INPUT);
  // OTA başlatma
  updateHandler.beginOTA();
  Serial.println("OTA güncellemesi için hazır");
}

void loop()
{
  if (digitalRead(Pins[12]) == HIGH)
  {
    Serial.println("Yükseklik hesaplama butonuna bastınız.\nYükseklik değeri hesaplanıyor...");
    flood.get_height();
    hcheck = true;
  }
  firegs.check();
  if (hcheck == true)
  {
    flood.control();
  }
  if (digitalRead(Pins[5]) == HIGH)
  {
    Serial.println("Mobil yardım butonuna bastınız.\nSüreç Başlatılıyor...");
    mobil.help_me_mobile();
  }
  if (digitalRead(Pins[6]) == HIGH)
  {
    Serial.println("Ev içi yardım butonuna bastınız.\nSüreç Başlatılıyor...");
    home.help_me_home();
  }
  telegram.telegram_update();
  earthquake.detect();
  updateHandler.handleOTA();
}
