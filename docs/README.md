# <div align="center">📚 Dokümantasyon</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=120&section=header&text=AUS%20Dokümantasyon&fontSize=30&fontColor=ffffff&animation=fadeIn&fontAlignY=25" alt="Documentation" />
</div>

<div align="center">
  <img src="https://media.giphy.com/media/l3q2Pb3RTnNrGCfmM/giphy.gif" alt="Documentation" width="450" />
</div>

Bu klasör, Akıllı Ev ve Afet Uyarı Sistemi (AUS) projesinin dokümantasyonunu içerir.

## <div align="center">⚙️ Teknik Dokümantasyon</div>

<div align="center">
  <img src="https://media.giphy.com/media/xTiTnBvYeOzjnS3UpO/giphy.gif" alt="Technical Documentation" width="400" />
</div>

### <div align="center">🔌 Sensörler</div>

<div align="center">
  <table>
    <tr>
      <th width="20%">Sensör</th>
      <th width="20%">Model</th>
      <th width="30%">Fonksiyon</th>
      <th width="30%">Teknik Özellikler</th>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/l0FeaNyrA8fUhx55u/giphy.gif" width="100" /><br/>
        <b>Yangın ve Gaz Sensörleri</b>
      </td>
      <td>
        <ul>
          <li>Flame Sensor</li>
          <li>MQ-2 Gas Sensor</li>
        </ul>
      </td>
      <td>
        Yangın, duman ve gaz algılama sensörleri kullanılarak potansiyel yangın tehlikeleri tespit edilir.
      </td>
      <td>
        <ul>
          <li>Analog ve dijital çıkış</li>
          <li>3.3V-5V çalışma voltajı</li>
          <li>Algılama mesafesi: 20-100 cm</li>
          <li>LPG, i-butane, propane, metan ve alkol algılama</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/SXlA8XSgz1ZO9BdXB2/giphy.gif" width="100" /><br/>
        <b>Sel Sensörü</b>
      </td>
      <td>
        <ul>
          <li>HC-SR04 Ultrasonik Sensör</li>
        </ul>
      </td>
      <td>
        Ultrasonik sensör kullanılarak su seviyesi ölçülür ve sel riski belirlenir.
      </td>
      <td>
        <ul>
          <li>Ölçüm aralığı: 2cm - 400cm</li>
          <li>Çözünürlük: 0.3cm</li>
          <li>Ultrasonik frekans: 40Hz</li>
          <li>5V çalışma voltajı</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/3oKIPvxGc4SMfoEaHK/giphy.gif" width="100" /><br/>
        <b>Deprem Sensörü</b>
      </td>
      <td>
        <ul>
          <li>ADXL345 İvmeölçer</li>
        </ul>
      </td>
      <td>
        ADXL345 ivmeölçer kullanılarak sarsıntı algılanır ve deprem tehlikesi tespit edilir.
      </td>
      <td>
        <ul>
          <li>3 eksenli ivmeölçer (X, Y, Z)</li>
          <li>13-bit çözünürlük (3.9mg/LSB)</li>
          <li>±2g, ±4g, ±8g, ±16g hassasiyet seçenekleri</li>
          <li>I2C ve SPI arayüzü desteği</li>
          <li>Düşük güç tüketimi (standby: 0.1µA)</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/YOT0zQXXuBfcZkA0W1/giphy.gif" width="100" /><br/>
        <b>Sıcaklık ve Nem Sensörü</b>
      </td>
      <td>
        <ul>
          <li>DHT11</li>
        </ul>
      </td>
      <td>
        DHT11 sensörü kullanılarak ortam sıcaklığı ve nem değerleri ölçülür.
      </td>
      <td>
        <ul>
          <li>Nem ölçüm aralığı: 20-90% RH</li>
          <li>Nem ölçüm hassasiyeti: ±5% RH</li>
          <li>Sıcaklık ölçüm aralığı: 0-50°C</li>
          <li>Sıcaklık ölçüm hassasiyeti: ±2°C</li>
          <li>Örnekleme hızı: 1Hz (1 okuma/saniye)</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

### <div align="center">📡 İletişim Protokolleri</div>

<div align="center">
  <table>
    <tr>
      <th width="25%">Protokol</th>
      <th width="25%">Teknoloji</th>
      <th width="50%">Açıklama</th>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/l0HUhn3CCwUUQu0Gk/giphy.gif" width="100" /><br/>
        <b>Telegram</b>
      </td>
      <td>
        <ul>
          <li>Telegram Bot API</li>
          <li>UniversalTelegramBot kütüphanesi</li>
          <li>WiFiClientSecure</li>
        </ul>
      </td>
      <td>
        <p>Telegram Bot API kullanılarak anlık bildirimler gönderilir. Kullanıcılar Telegram uygulaması üzerinden:</p>
        <ul>
          <li>Sensör verilerini görüntüleyebilir</li>
          <li>Sistem durumunu kontrol edebilir</li>
          <li>Acil durum bildirimlerini alabilir</li>
          <li>Bazı sistem fonksiyonlarını kontrol edebilir</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/1nZEdr5B5qnrRZat47/giphy.gif" width="100" /><br/>
        <b>E-posta</b>
      </td>
      <td>
        <ul>
          <li>SMTP Protokolü</li>
          <li>ESP32 WiFi</li>
        </ul>
      </td>
      <td>
        <p>SMTP protokolü ile acil durum bildirimleri e-posta olarak gönderilir. Bildirimler:</p>
        <ul>
          <li>Yangın/duman algılandığında</li>
          <li>Su baskını riski tespit edildiğinde</li>
          <li>Deprem sarsıntısı ölçüldüğünde</li>
          <li>Panik butonu etkinleştirildiğinde</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/l2SpYdthCZcXeggyk/giphy.gif" width="100" /><br/>
        <b>OTA Güncelleme</b>
      </td>
      <td>
        <ul>
          <li>ArduinoOTA</li>
          <li>ESP32 WiFi</li>
        </ul>
      </td>
      <td>
        <p>ESP32/ESP8266 için kablosuz güncelleme desteği sağlanır. OTA özellikleri:</p>
        <ul>
          <li>Firmware uzaktan güncelleme</li>
          <li>Fiziksel erişim olmadan yazılım iyileştirmeleri</li>
          <li>Güvenli güncellemeler için doğrulama</li>
          <li>Ağ üzerinden otomatik cihaz güncellemesi</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

### <div align="center">🎮 Kontrol Sistemleri</div>

<div align="center">
  <table>
    <tr>
      <th width="30%">Sistem</th>
      <th width="70%">Açıklama</th>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/NRl6T4BjyCO7RRZ00q/giphy.gif" width="100" /><br/>
        <b>Panik Butonları</b>
      </td>
      <td>
        <p>Mobil ve ev içi yardım butonları ile acil durum bildirimleri tetiklenir:</p>
        <ul>
          <li><b>Ev İçi Panik Butonu (GPIO19):</b> Evdeki acil durumlar için bir buton</li>
          <li><b>Mobil Panik Butonu (GPIO15):</b> Taşınabilir, kullanıcının yanında bulundurulabilir</li>
          <li>Butonlara basıldığında, konum bilgisi ve standart acil durum mesajı gönderilir</li>
          <li>Telegram ve e-posta üzerinden anında bildirimler gönderilir</li>
          <li>LED arayüzü ve buzzer ile sesli ve görsel bildirim sağlanır</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

### <div align="center">💻 Arayüz Bileşenleri</div>

<div align="center">
  <table>
    <tr>
      <th width="30%">Bileşen</th>
      <th width="70%">Açıklama</th>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/3oKIPvxGc4SMfoEaHK/giphy.gif" width="100" /><br/>
        <b>LED</b>
      </td>
      <td>
        <p>RGB LED ile durum bildirimleri görsel olarak gösterilir:</p>
        <ul>
          <li><b>Kırmızı LED (GPIO13):</b> Acil durum veya alarm durumu</li>
          <li><b>Yeşil LED (GPIO12):</b> Normal çalışma durumu</li>
          <li><b>Mavi LED (GPIO14):</b> İletişim ve veri aktarımı</li>
          <li>Farklı yanıp sönme modları ile farklı durumlar temsil edilir</li>
          <li>Düşük ışık seviyesinde otomatik parlaklık ayarı</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/5xaOcLIbCU6KZwDPyaQ/giphy.gif" width="100" /><br/>
        <b>Buzzer</b>
      </td>
      <td>
        <p>Sesli uyarı sistemi ile bildirimler gerçekleştirilir (GPIO17):</p>
        <ul>
          <li><b>Kısa Bip:</b> Standart bildirim</li>
          <li><b>Uzun Bip:</b> Kullanıcı etkileşimi gerektiğinde</li>
          <li><b>SOS Deseni:</b> Acil durum bildirimi</li>
          <li><b>Hızlı Tekrarlı Bip:</b> Kritik uyarı</li>
          <li>Gece modu ile belirli saatlerde otomatik ses kısılma özelliği</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

## <div align="center">📄 Devre Şeması</div>

<div align="center">
  <img src="https://media.giphy.com/media/26tn33aiTi1jkl6H6/giphy.gif" alt="Circuit Diagram" width="500" />
  <p><i>Örnek ESP32 sensör bağlantı şeması</i></p>
</div>

<div align="center">
  <table>
    <tr>
      <th>Bileşen</th>
      <th>ESP32 Bağlantısı</th>
      <th>Güç Kaynağı</th>
    </tr>
    <tr>
      <td>Alev Sensörü</td>
      <td>GPIO23 (Digital)</td>
      <td>3.3V</td>
    </tr>
    <tr>
      <td>MQ-2 Gaz Sensörü</td>
      <td>GPIO36 (Analog), GPIO34 (Digital)</td>
      <td>5V</td>
    </tr>
    <tr>
      <td>HC-SR04 Ultrasonik</td>
      <td>GPIO5 (Trig), GPIO18 (Echo)</td>
      <td>5V</td>
    </tr>
    <tr>
      <td>DHT11 Sıcaklık/Nem</td>
      <td>GPIO3</td>
      <td>3.3V</td>
    </tr>
    <tr>
      <td>RGB LED</td>
      <td>GPIO13 (R), GPIO12 (G), GPIO14 (B)</td>
      <td>3.3V via 220Ω dirençler</td>
    </tr>
    <tr>
      <td>Buzzer</td>
      <td>GPIO17</td>
      <td>3.3V</td>
    </tr>
    <tr>
      <td>Panik Butonları</td>
      <td>GPIO15 (Mobil), GPIO19 (Ev)</td>
      <td>3.3V (Pull-down dirençleri ile)</td>
    </tr>
    <tr>
      <td>ADXL345 İvmeölçer</td>
      <td>GPIO21 (SDA), GPIO22 (SCL)</td>
      <td>3.3V</td>
    </tr>
  </table>
</div>

## <div align="center">📔 Kullanıcı Kılavuzu</div>

<div align="center">
  <img src="https://media.giphy.com/media/3o6ZsXHLRnkgPtEYVi/giphy.gif" alt="User Guide" width="400" />
</div>

<div align="center">
  <p>Detaylı kurulum ve kullanım bilgileri için ana klasördeki <a href="../README.md">README.md</a> dosyasına bakınız.</p>
  <p>Hızlı başlangıç için aşağıdaki kaynaklara göz atabilirsiniz:</p>
</div>

<div align="center">
  <table>
    <tr>
      <td align="center" width="33%">
        <a href="../README.md#kurulum-ve-konfigürasyon">
          <img src="https://media.giphy.com/media/MCeHiUs7nODJHlR4rX/giphy.gif" width="100" />
          <br/><b>Kurulum Kılavuzu</b>
        </a>
      </td>
      <td align="center" width="33%">
        <a href="../test/README.md">
          <img src="https://media.giphy.com/media/XAxylRMCdpbEWUAvr8/giphy.gif" width="100" />
          <br/><b>Test Senaryoları</b>
        </a>
      </td>
      <td align="center" width="33%">
        <a href="../README.md#telegram-komutları">
          <img src="https://media.giphy.com/media/ZZlFeURejAu7o0esKN/giphy.gif" width="100" />
          <br/><b>Telegram Komutları</b>
        </a>
      </td>
    </tr>
  </table>
</div>

<div align="center">
  <table style="background-color: #101728; width: 85%; margin: 25px auto; border-collapse: collapse; border-radius: 8px; overflow: hidden; border-left: 5px solid #0891b2;">
    <tr>
      <td style="padding: 20px; text-align: left;">
        <p><i><b>"Modern ev güvenliği, sensörler ve akıllı bildirimlerle başlar."</b></i></p>
        <p>Her ev sahibi, AUS sistemini kurarken şu temel ilkeleri dikkate almalıdır:</p>
        <ol>
          <li>Sensörleri, algılanacak tehlikelere en yakın konumlara yerleştirin</li>
          <li>WiFi sinyalinin güçlü olduğu bir konumda ESP32'yi konumlandırın</li>
          <li>Güç kesintisine karşı yedek pil sistemi kullanın</li>
          <li>Periyodik bakım ve test işlemlerini düzenli olarak yapın</li>
          <li>Tüm aile üyelerine sistemin kullanımını öğretin</li>
        </ol>
        <p>Bu sistem, felaketleri engelleyemez ancak erken uyarı ile can ve mal kayıplarını minimize etmeyi amaçlar.</p>
      </td>
    </tr>
  </table>
</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=100&section=footer&fontSize=18&fontColor=ffffff&animation=fadeIn" alt="Footer" />
</div> 