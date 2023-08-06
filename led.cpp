#include "led.h"

LedControl::LedControl(int redPin, int greenPin, int bluePin, int time, int replay) /* Led kütüphanesi yapıcı methodu*/
{
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
  _time = time;
  _replay = replay;
  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
}

void LedControl::on(String colorCode) /* Ledi istenilen RGB koda göre açan fonksiyon*/
{
  rgb_convert(colorCode);
}

void LedControl::error(String color) /* Hata durum koduna göre Led yakan fonksiyon */
{
  if (color == "smoke")
  {
    // Smoke (duman) için: #9E9E9E (gri renk tonu)
    rgb_convert("#9E9E9E");
  }
  else if (color == "fire")
  {
    // Fire (yangın) için: #FF0000 (kırmızı renk tonu)
    rgb_convert("#FF0000");
  }
  else if (color == "flood")
  {
    // Flood (sel) için: #0066FF (mavi renk tonu)
    rgb_convert("#0066FF");
  }
  else if (color == "panic-home")
  {
    // Panic-home (evde panik) için: #FFFF00 (sarı renk tonu)
    rgb_convert("#FFFF00");
  }
  else if (color == "panic-mobil")
  {
    // Panic-mobil (dış ortam panik) için: #FF6600 (turuncu renk tonu)
    rgb_convert("#FF6600");
  }
  else
    rgb_convert(color);
}

void LedControl::off(void) /* Ledi söndüren fonksiyon */
{
  rgb_convert("#000000");
}

void LedControl::rgb_convert(String colorCode) /* İstenilen renk kodunu (hex) analog değere dönüştüren fonksiyon */
{
  int red, green, blue;
  red = strtoul(colorCode.substring(1, 3).c_str(), NULL, 16);
  green = strtoul(colorCode.substring(3, 5).c_str(), NULL, 16);
  blue = strtoul(colorCode.substring(5, 7).c_str(), NULL, 16);
  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
}

void LedControl::strobing(String colorCode) /* İstenilen renk koduna göre yanıp sönme efekti veren fonksiyon */
{
  for (int i = 0; i < _replay; i++)
  {
    rgb_convert(colorCode);
    delay(_time);
    off();
  }
}
/*
void LedControl::color_cycle(int delay_time) {
  for (int i = 255; i >= 0; i--) {
    analogWrite(_redPin, i);
    delay(delay_time);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(_greenPin, i);
    delay(delay_time);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(_bluePin, i);
    delay(delay_time);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(_redPin, i);
    delay(delay_time);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(_greenPin, i);
    delay(delay_time);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(_bluePin, i);
    delay(delay_time);
  }
}
*/