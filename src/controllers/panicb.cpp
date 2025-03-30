#include "panicb.h"

WiFiClientSecure client;

MobileButton::MobileButton(int port, int red, int green, int blue) /* Mobil panik butonu sınıfı yapıcı methodu*/
{
  _apiUrl = "/ipgeo?apiKey=";
  _apiKey = "58cdfb4580514ab2848f339e5603af7d";
  _apiHost = "api.ipgeolocation.io";
  _port = port;
  _redPin = red;
  _greenPin = green;
  _bluePin = blue;
}

bool MobileButton::connect() /* Api sunucusu bağlantısı kuran fonksiyon */
{
  client.setInsecure();
  if (!client.connect(_apiHost.c_str(), _port))
  {
    Serial.println("Connection failed");
    return false;
  }
  return true;
}

bool MobileButton::fetch_data() /* Api sunucusundan veriyi çeken fonksiyon */
{
  _jdata.clear();
  client.println("GET " + _apiUrl + _apiKey + " HTTP/1.1\r\nHost: " + _apiHost + "\r\n\r\n");
  Serial.print("\r\nReading response...");
  while (client.connected())
  {
    delay(100);
    _jdata += client.readStringUntil('\n');
  }

  if (_jdata.isEmpty())
  {
    Serial.println("jdata içerisinde hicbir sey yazilamadi");
    return false;
  }
  else
    client.stop();
  return true;
}

bool MobileButton::get_location() /* connect ve fetch data fonksiyonlarını kontrol eden fonksiyon */
{
  bool check = true;
  while (check)
    if (connect() == true)
      check = false;
  check = true;
  while (check)
    if (fetch_data() == true)
      check = false;
}

DynamicJsonDocument MobileButton::clean_data() /* gelen veriyi gereksiz kısımları temizleyerek kullanılabilir konum bilgisine dönüştüren fonksiyon*/
{
  DynamicJsonDocument doc(1024);
  int startIndex = _jdata.indexOf("{");
  int endIndex = _jdata.lastIndexOf("}");
  if (startIndex < 0 || endIndex < 0)
    return doc;
  _jdata = _jdata.substring(startIndex, endIndex + 1);
  deserializeJson(doc, _jdata);
  return doc;
}

bool MobileButton::parse_data() /* temizlenmiş veriyi parçalara ayırarak istenilen şekilde kullanımını sağlayan fonksiyon*/
{
  DynamicJsonDocument jsonData = clean_data();
  if (!jsonData.isNull())
  {
    String ip = jsonData["ip"];
    String country_name = jsonData["country_name"];
    String city = jsonData["city"];
    String zipcode = jsonData["zipcode"];
    String latitude = jsonData["latitude"];
    String longitude = jsonData["longitude"];
    String who_mess = "\nPanic Button tarafından gönderilmiştir ve başım belada. Lütfen konum bilgilerime yardım gönderin.\n";
    _message.clear();
    _message = ("IP: " + ip + "\nUlke: " + country_name + "\nSehir: " + city + "\nZip Kodu: " + zipcode + "\nEnlem: " + latitude + "\nBoylam: " + longitude + who_mess);
    return true;
  }
  return false;
}

bool MobileButton::send_mobile_mail() /* mail kütüphanesiyle iletişime geçmeyi sağlayan fonksiyon*/
{
  MailSender mobilmail("Mobil Panik Butonu", "Mobil Panik Butonu Bildirimi!", "Mobil Acil Durum Bildirimi!", _message, "Acil Durum Merkezi!", "ertugrul.sunum@gmail.com");
  if (mobilmail.send_email() == true)
    return true;
  else
    return false;
}

void MobileButton::help_me_mobile() /* tüm işleyişi sağlayan mobil class kütüphane fonksiyonu*/
{
  LedControl ledmobil(_redPin, _greenPin, _bluePin, 300, 7);
  ledmobil.error("panic-mobil");
  bool status = true;
  while (status)
  {
    if (get_location() == true)
      status = false;
    delay(2000);
  }
  status = true;
  while (status)
  {
    if (parse_data() == true)
      status = false;
    delay(2000);
  }
  status = true;
  while (status)
  {
    if (send_mobile_mail() == true)
      status = false;
    delay(2000);
  }
  ledmobil.off();
}

/*Home Button*/

HomeButton::HomeButton(int red, int green, int blue) /* Home panik butonu sınıfı yapıcı methodu*/
{
  _redPin = red;
  _greenPin = green;
  _bluePin = blue;
}

void HomeButton::help_me_home() /* tüm işleyişi sağlayan home class kütüphane fonksiyonu*/
{
  LedControl ledhome(_redPin, _greenPin, _bluePin, 300, 7);
  ledhome.error("panic-home");
  bool status = true;
  while (status)
  {
    if (send_home_mail() == true)
      status = false;
    delay(2000);
  }
  ledhome.off();
}

bool HomeButton::send_home_mail() /* mail kütüphanesiyle iletişime geçmeyi sağlayan fonksiyon*/
{
  _message.clear();
  _message = "\nBilecik Şeyh Edebali Üniversitesi, Mühendislik Fakültesi, C Blok, Anfi 1 salonu, 42 numarali sirada oturuyorum. Yardima ihtiyacim var.\n";
  MailSender homemail("Home Panik Butonu", "Home Panik Butonu Bildirimi!", "Home Acil Durum Bildirimi!", _message, "Acil Durum Merkezi!", "ertugrul.sunum@gmail.com");
  if (homemail.send_email() == true)
    return true;
  else
    return false;
}