# <div align="center">💻 Kaynak Kodlar</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=120&section=header&text=AUS%20Kaynak%20Kodları&fontSize=30&fontColor=ffffff&animation=fadeIn&fontAlignY=25" alt="Source Code" />
</div>

<div align="center">
  <img src="https://media.giphy.com/media/26n7b7PjSOZJwVCmY/giphy.gif" alt="Source Code" width="450" />
</div>

<div align="center">
  <a href="../README.md">
    <img src="https://img.shields.io/badge/↩️ Ana%20Sayfa-0891b2?style=for-the-badge" alt="Ana Sayfa" />
  </a>
  <a href="../docs/README.md">
    <img src="https://img.shields.io/badge/📚 Dokümantasyon-0891b2?style=for-the-badge" alt="Dokümantasyon" />
  </a>
  <a href="../test/README.md">
    <img src="https://img.shields.io/badge/🧪 Test-0891b2?style=for-the-badge" alt="Test" />
  </a>
</div>

Bu dizin, Akıllı Ev ve Afet Uyarı Sistemi (AUS) projesinin kaynak kodlarını içerir.

## <div align="center">📁 Dizin Yapısı</div>

<div align="center">
  <table>
    <tr>
      <th width="25%">Dizin/Dosya</th>
      <th width="75%">Açıklama</th>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/UWZejVFBGmHwynFvP3/giphy.gif" width="80" /><br/>
        <b>aus-ertugrul.ino</b>
      </td>
      <td>
        Ana program dosyası. Tüm sensörleri, iletişim protokollerini ve kontrol mekanizmalarını bir araya getiren ve yöneten dosya.
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/VdoIFLsMIlwzfKD520/giphy.gif" width="80" /><br/>
        <b>test.ino</b>
      </td>
      <td>
        Test amaçlı ana dosya. Sensörlerin ve diğer bileşenlerin test edilmesi için kullanılır.
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/VgGthkhUvGgOit7Y9i/giphy.gif" width="80" /><br/>
        <b>sensors/</b>
      </td>
      <td>
        Yangın, sel, deprem, sıcaklık ve nem sensörlerine ait kod dosyalarını içerir.
        <ul>
          <li><b>fire.h/cpp</b>: Yangın ve gaz sensörleri için sınıflar ve fonksiyonlar</li>
          <li><b>flood.h/cpp</b>: Sel sensörleri için sınıflar ve fonksiyonlar</li>
          <li><b>earthquake.h/cpp</b>: Deprem sensörleri için sınıflar ve fonksiyonlar</li>
          <li><b>heathum.h/cpp</b>: Sıcaklık ve nem sensörleri için sınıflar ve fonksiyonlar</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/kHsn4Y4WGQQoG4YG9s/giphy.gif" width="80" /><br/>
        <b>communication/</b>
      </td>
      <td>
        İletişim protokollerine ait kod dosyalarını içerir.
        <ul>
          <li><b>telegram.h/cpp</b>: Telegram bot entegrasyonu için sınıflar ve fonksiyonlar</li>
          <li><b>mail.h/cpp</b>: E-posta bildirimleri için sınıflar ve fonksiyonlar</li>
          <li><b>update.h/cpp</b>: OTA güncellemeleri için sınıflar ve fonksiyonlar</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/ZZlFeURejAu7o0esKN/giphy.gif" width="80" /><br/>
        <b>controllers/</b>
      </td>
      <td>
        Kontrol sistemlerine ait kod dosyalarını içerir.
        <ul>
          <li><b>panicb.h/cpp</b>: Panik butonları için sınıflar ve fonksiyonlar</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExYmdneDBnbjdxZG15cGRzb25seGx5aWpvZzl3OGxvajgweHJxOXc0dSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/QWaYdviCrH9Kx2qmVs/giphy.gif" width="80" /><br/>
        <b>interfaces/</b>
      </td>
      <td>
        Arayüz elemanlarına ait kod dosyalarını içerir.
        <ul>
          <li><b>led.h/cpp</b>: LED kontrolleri için sınıflar ve fonksiyonlar</li>
          <li><b>buzzer.h/cpp</b>: Sesli uyarı için sınıflar ve fonksiyonlar</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExNGk1bncxa2U2d2EzZGU2ODBybnlrNmtkdDZjamVrd2ttaDdzM2p6dCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/L1R1tvI9svkIWwpVYr/giphy.gif" width="80" /><br/>
        <b>utils/</b>
      </td>
      <td>
        Yardımcı fonksiyonlara ait kod dosyalarını içerir.
        <ul>
          <li><b>other.h/cpp</b>: WiFi bağlantısı ve diğer yardımcı fonksiyonlar</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

## <div align="center">🧩 Kod Örnekleri</div>

<div align="center">
  <img src="https://media.giphy.com/media/26tn33aiTi1jkl6H6/giphy.gif" alt="Code Examples" width="450" />
</div>

### 📌 Ana Loop

```cpp
void loop() {
  // Telegram mesajlarını işle
  if (millis() - bot_lasttime > BOT_MTBS) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    bot_lasttime = millis();
  }
  
  // Sensör verilerini oku
  readSensors();
  
  // Acil durum kontrolleri
  checkEmergency();
  
  // LED ve buzzer durumlarını güncelle
  updateInterfaces();
}
```

### 📌 Sensör Okuma Örneği

```cpp
void readSensors() {
  // Yangın sensörü
  flameValue = digitalRead(FLAME_PIN);
  
  // Gaz sensörü
  gasValue = analogRead(GAS_PIN);
  
  // Nem ve sıcaklık sensörü
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  // Ultrasonik sensör
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  waterLevel = duration * 0.034 / 2;
}
```

## <div align="center">⚙️ Derleme ve Yükleme</div>

Kodu derlemek ve ESP32'ye yüklemek için şu adımları izleyin:

1. Arduino IDE'yi açın ve ESP32 desteğini ekleyin
2. Tüm gerekli kütüphaneleri yükleyin (bkz. [Ana Sayfa - Kurulum](../README.md#kurulum-ve-konfigürasyon))
3. `aus-ertugrul.ino` dosyasını açın
4. ESP32 kartını seçin ve doğru portu ayarlayın
5. Yükle düğmesine tıklayın

Test modunda çalıştırmak için `test.ino` dosyasını açıp yükleyin.

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=100&section=footer&text=AUS%20Kaynak%20Kodları&fontSize=14&fontColor=ffffff&animation=fadeIn&fontAlignY=80" alt="Footer" />
</div> 