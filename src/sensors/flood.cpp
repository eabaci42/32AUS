#include "flood.h"

FloodSensor::FloodSensor(int trigPin, int echoPin, int itarator, int time, int buzzer, int red, int green, int blue, const String userIds[], int usercount) /* Flood kütüphanesi yapıcı methodu*/
{
  _trigPin = trigPin;
  _echoPin = echoPin;
  _replay = itarator;
  _time = time;
  _buzzer = buzzer;
  _redPin = red;
  _greenPin = green;
  _bluePin = blue;
  _userCount = usercount;
  for (int i = 0; i < _userCount; i++)
  {
    _userIds[i] = userIds[i];
  }
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

void FloodSensor::get_height() /* Oda yüksekliğini tespit edip ayarlayan fonksiyon */
{                              // oda yüksekliği bulundu.

  int readings[_replay];
  float geoAvr = 1.0;
  int readIndex = 0;
  int check = 0;
  bool loop = true;

  while (loop)
  {
    check = calculate_height();
    if (check > 0 && check <= 400)
    {
      readings[readIndex] = check;
      Serial.println("Index: " + String(readIndex) + " | Mesafe: " + String(check) + " cm");

      if (readIndex >= (_replay))
      {
        geoAvr = 1.0;
        for (int i = 0; i < _replay; i++)
        {
          geoAvr *= readings[i];
        }

        geoAvr = pow(geoAvr, 1.0 / _replay);
        Serial.println("Tavan Yuksekligi: " + String(geoAvr) + " cm");
        loop = false;
      }
      readIndex++;
      delay(_time);
    }
    else
    {
      Serial.println("Sorun var duzgun olculemedi: " + String(check) + " cm");
    }
    check = 0;

    delay(_time);
  }
  _height = geoAvr;
}

float FloodSensor::calculate_height() /* Mesafe hesaplayan özel fonksiyon */
{                                     // yükseklik ölçümü yapıyor
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  float duration = pulseIn(_echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

bool FloodSensor::check_warning() /* Su baskınını tespit eden fonksiyon */
{                                 // Sel uyarısı var ya da yok şeklinde dönüyor
  float water;

  water = calculate_height();
  delay(_time);
  if ((_height / 2.0) > water)
  {
    _yukseklik = water;
    Serial.println("Su seviyesi: " + String(water) + " cm");
    delay(2000);
    return true;
  }
  return false;
}

void FloodSensor::control() /* Su baskınına karar veren fonksiyon */
{
  bool controlmail;
  bool controltelegram;
  bool check;
  controlmail = true;
  controltelegram = true;
  LedControl led(_redPin, _greenPin, _bluePin, 300, 7);
  BuzzerControl buzzer(_buzzer);
  if (check_warning() == true)
  {
    led.error("flood");
    buzzer.buzzer_high();
    while (controlmail == true || controltelegram == true)
    {
      if (controlmail == true)
      {
        controlmail = !mail_notification();
      }
      if (controltelegram == true)
      {
        controltelegram = !telegram_notification();
      }
    }
  }
}
else
{
  led.off();
  buzzer.buzzer_low();
}
}

bool FloodSensor::mail_notification() /* Mail kütüphanesiyle mail gönderimini sağlayan fonksiyon */
{
  _message = ("\n Evinizde su seviyesi kritik seviye olan " + String(_height) + " cm " + "üstüne cikti.");
  MailSender floodmail("Flood Chech System", "Sel Sistemi Bildirimi!", "Sel Acil Durum Bildirimi!", _message, "Acil Durum Merkezi!", "ertugrul.sunum@gmail.com");
  if (floodmail.send_email() == true)
    return true;
  else
    return false;
}
/*
bool FloodSensor::telegram_notification()
{
  TelegramBot alarm(_userIds, _userCount);
  if (alarm.alarm_message(_message) == true)
    return true;
  else
    return false;
}*/
