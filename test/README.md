# <div align="center">🧪 Test Klasörü</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=120&section=header&text=AUS%20Test%20Modülü&fontSize=30&fontColor=ffffff&animation=fadeIn&fontAlignY=25" alt="Test Module" />
</div>

<div align="center">
  <img src="https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif" alt="Testing" width="450" />
</div>

Bu klasör, Akıllı Ev ve Afet Uyarı Sistemi (AUS) projesinin test senaryoları ve test araçları için ayrılmıştır.

## <div align="center">📋 Test Senaryoları</div>

<div align="center">
  <table>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/X0oEvTEdLj2YU/giphy.gif" alt="Flood Test" width="180"/>
        <h3>1️⃣ Sel Algılama Testi</h3>
        <p>Ultrasonik sensör ile su seviyesi ölçümünü test eder.</p>
        <p>Sensör: <code>HC-SR04</code></p>
        <p>Pinler: <code>TRIG:GPIO5</code>, <code>ECHO:GPIO18</code></p>
      </td>
      <td align="center">
        <img src="https://media.giphy.com/media/3o7TKSjRrfIPjeiVyM/giphy.gif" alt="Fire Test" width="180"/>
        <h3>2️⃣ Yangın ve Gaz Testi</h3>
        <p>Yangın sensörü ve gaz sensörlerinin çalışmasını test eder.</p>
        <p>Sensörler: <code>Flame Sensor</code>, <code>MQ-2</code></p>
        <p>Pinler: <code>FLAME:GPIO23</code>, <code>GAS:GPIO36/34</code></p>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img src="https://media.giphy.com/media/xT0xenCpqBGBvM2fFC/giphy.gif" alt="Earthquake Test" width="180"/>
        <h3>3️⃣ Deprem Algılama Testi</h3>
        <p>İvmeölçer ile deprem algılama fonksiyonunu test eder.</p>
        <p>Sensör: <code>ADXL345</code></p>
        <p>Bağlantı: <code>I2C (SDA:GPIO21, SCL:GPIO22)</code></p>
      </td>
      <td align="center">
        <img src="https://media.giphy.com/media/mRh4cLIYhrs9G/giphy.gif" alt="Panic Button Test" width="180"/>
        <h3>4️⃣ Panik Butonları Testi</h3>
        <p>Mobil ve ev içi yardım butonlarının çalışmasını test eder.</p>
        <p>Cihazlar: <code>Push Buttons</code></p>
        <p>Pinler: <code>MOBILE:GPIO15</code>, <code>HOME:GPIO19</code></p>
      </td>
    </tr>
  </table>
</div>

## <div align="center">🔧 Test Araçları</div>

<div align="center">
  <img src="https://media.giphy.com/media/VDGKJDJT64O5cHttaU/giphy.gif" alt="Testing Tools" width="400" />
</div>

<div align="center">
  <table>
    <tr>
      <td>
        <h3>⚡ Arduino Serial Monitor</h3>
        <p>Serial.begin(115200) hızında çalıştırılır</p>
        <p><code>src/test.ino</code> dosyası yüklendiğinde, Serial Monitor üzerinden test menüsü görüntülenir:</p>
        <pre>
=== Test Menüsü ===
1. Sel Sistemini Test Et
2. Yangın Sistemini Test Et
3. Deprem Sistemini Test Et
4. Panik Butonlarını Test Et
Lütfen bir test numarası girin:
        </pre>
      </td>
      <td>
        <h3>🛠️ Fiziksel Test Araçları</h3>
        <ul>
          <li><b>Su Seviye Simülatörü</b>: Ultrasonik sensör testleri için</li>
          <li><b>Simüle Alev Kaynağı</b>: Yangın sensörü testleri için LED</li>
          <li><b>Gaz Algılama Testi</b>: İzopropil alkol buharı (dikkatli kullanın!)</li>
          <li><b>İvme Simülatörü</b>: ADXL345 sensörünü farklı açılarda eğme</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

## <div align="center">🔄 Test İş Akışı</div>

<div align="center">
  <img src="https://media.giphy.com/media/3ohs4gux2zjc5OtjFe/giphy.gif" alt="Workflow" width="450" />
</div>

1. 📥 **Test Hazırlığı**
   - ESP32 kartını bilgisayarınıza bağlayın
   - `src/test.ino` dosyasını yükleyin
   - Gerekli test cihazlarını bağlayın

2. 🧪 **Test Çalıştırma**
   - Serial Monitor'ü açın (115200 baud)
   - Test menüsünden istediğiniz testi seçin (1-4)
   - Test sonuçlarını gözlemleyin

3. 📝 **Sonuçları Değerlendirme**
   - Sensör tepkilerini kontrol edin
   - Bildirim sistemlerinin çalışıp çalışmadığını doğrulayın
   - Hata veya gecikme sürelerini not edin

## <div align="center">📋 Test Kontrol Listesi</div>

<div align="center">
  <table>
    <tr>
      <th>Test Adımı</th>
      <th>Beklenen Sonuç</th>
      <th>Kontrol</th>
    </tr>
    <tr>
      <td>Yangın Sensörü Testi</td>
      <td>Sensör alev algıladığında LED kırmızıya dönmeli ve bildirim gelmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Gaz Sensörü Testi</td>
      <td>Gaz seviyesi eşiği aştığında buzzer çalmalı ve bildirim gönderilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Su Seviyesi Ölçümü</td>
      <td>Su seviyesi doğru ölçülmeli ve kritik değerlerde uyarı verilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Deprem Algılama</td>
      <td>İvmeölçer şiddetli hareketi algıladığında bildirim gönderilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Ev İçi Panik Butonu</td>
      <td>Butona basıldığında LED yanmalı ve yardım mesajı gönderilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Mobil Panik Butonu</td>
      <td>Butona basıldığında konum bilgisi ve yardım mesajı gönderilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>Telegram Bot Yanıtları</td>
      <td>Komutlara doğru ve hızlı yanıt verilmeli</td>
      <td>▢</td>
    </tr>
    <tr>
      <td>OTA Güncelleme</td>
      <td>Kablosuz yazılım güncellemesi sorunsuz çalışmalı</td>
      <td>▢</td>
    </tr>
  </table>
</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=100&section=footer&fontSize=18&fontColor=ffffff&animation=fadeIn" alt="Footer" />
</div> 