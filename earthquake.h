#ifndef Earthquake_h
#define Earthquake_h

#include <Wire.h>
#include <ADXL345.h>
#include "mail.h" // Mail gönderme kütüphanesini buraya dahil edin (uygun şekilde adını güncelleyin)

class Earthquake
{
private:
  ADXL345 accel;
  double threshold;
  String _message;
  String _userIds[10];
  int _userCount;

public:
  Earthquake(double threshold, uint8_t i2cAddress = ADXL345_ALT, TwoWire *wire = &Wire);
  bool begin();
  void detect();
  bool mail_notification(); // Mail gönderme işlevi
  bool telegram_notification();

  // Diğer işlevler...
};

#endif
