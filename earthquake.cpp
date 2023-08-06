#include "Earthquake.h"

Earthquake::Earthquake(double threshold, const String userIds[], int usercount, uint8_t i2cAddress, TwoWire *wire)
    : accel(i2cAddress, wire), threshold(threshold)
{
    _userCount = usercount;
    for (int i = 0; i < _userCount; i++)
    {
        _userIds[i] = userIds[i];
    }
}

bool Earthquake::begin()
{
    if (!accel.start())
    {
        return false;
    }
    return true;
}

void Earthquake::detect()
{
    bool eqdedect = false;
    if (accel.update())
    {
        double x = accel.getX();
        double y = accel.getY();
        double z = accel.getZ();

        double magnitude = sqrt(x * x + y * y + z * z);

        eqdedect = magnitude > threshold;
    }
    else
        eqdedect false;

    if (eqdedect == true)
    {
        Serial.println("Earthquake detected!");
        _message = "Deprem tespit edildi!" mail_notification();
        telegram_notification();
    }
    else
    {
        Serial.println(magnitude);
    }
}

bool Earthquake::mail_notification() /* Mail kütüphanesine gerekli bilgileri gönderen ve mail gönderimini sağlayan fonksiyon*/
{
    MailSender eart("Earthquake System", "Deprem Sarsıntısı Bildirimi!", "Deprem Sarsıntısı Bildirimi!", _message, "Acil Durum Merkezi!", "ertugrul.sunum@gmail.com");
    if (eart.send_email() == true)
        return true;
    else
        return false;
}
bool Earthquake::telegram_notification()
{
    TelegramBot alarm(_userIds, _userCount);
    if (alarm.alarm_message(_message) == true)
        return true;
    else
        return false;
}