#include "buzzer.h"

BuzzerControl::BuzzerControl(int buzzerPin) /*Buzzer kütüphanesi yapıcı methotu*/
{
  _buzzerPin = buzzerPin;
  pinMode(_buzzerPin, OUTPUT);
}

void BuzzerControl::buzzer_high() /* Buzzeri çalıştıran fonksiyon*/
{
  digitalWrite(_buzzerPin, HIGH);
}

void BuzzerControl::buzzer_low() /* Buzzeri çalışmasını durduran fonksiyon*/
{
  digitalWrite(_buzzerPin, LOW);
}