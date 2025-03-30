# <div align="center">🧪 Test</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=150&section=header&text=AUS%20Test%20Modülü&fontSize=40&fontColor=ffffff&animation=fadeIn&fontAlignY=38" alt="Test Modülü" />
</div>

<p align="center">
  <img src="https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif" alt="Test" width="200" />
  <br>
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=18&duration=2000&pause=500&color=0891B2&center=true&vCenter=true&width=450&lines=Test+Senaryoları;Kalite+Kontrol;Fonksiyon+Testleri;Sistem+Testleri;Bileşen+Testleri" alt="Typing SVG" />
</p>

<div align="center">
  <a href="../README.md">
    <img src="https://img.shields.io/badge/Ana%20Sayfa-0891b2?style=for-the-badge" alt="Ana Sayfa" />
  </a>
</div>

## 📋 Genel Bakış
Bu klasör, Akıllı Ev ve Afet Uyarı Sistemi (AUS) projesinin test senaryoları ve test araçları için ayrılmıştır. Sistemin doğru çalıştığından emin olmak için farklı bileşenlerin ve işlevlerin test edilmesine yönelik dökümanları içerir.

## 📝 Test Senaryoları

| Test Senaryosu | Açıklama | Kontrol Noktaları |
|----------------|----------|-------------------|
| **Yangın Algılama Testi** | Alev sensörü ve gaz sensörünün doğru çalışıp çalışmadığını test eder | Alev algılama, gaz seviyesi ölçümü, alarm tetikleme, bildirim gönderme |
| **Sel Algılama Testi** | Ultrasonik sensör ile su seviyesi ölçümünün doğruluğunu test eder | Mesafe ölçümü, su seviyesi eşikleri, alarm tetikleme |
| **Deprem Algılama Testi** | İvmeölçerin titreşim algılamasını test eder | X,Y,Z eksen değerleri, titreşim şiddeti hesaplama, alarm tetikleme |
| **Panik Buton Testi** | Ev içi ve mobil panik butonlarının çalışmasını test eder | Buton basma, alarm tetikleme, bildirim gönderme |
| **İletişim Testi** | Telegram bot ve e-posta bildirimlerinin çalışmasını test eder | Mesaj gönderme, komut algılama, bildirim içeriği doğrulama |

## 🔧 Test Prosedürü

1. Arduino IDE'yi açın ve ESP32 kartınızı bilgisayarınıza bağlayın
2. `src/test.ino` dosyasını kartınıza yükleyin
3. Serial Monitor'ü açın (115200 baud rate)
4. Test menüsünden bir test seçeneği seçin:
   ```
   === Test Menüsü ===
   1. Sel Sistemini Test Et
   2. Yangın Sistemini Test Et
   3. Deprem Sistemini Test Et
   4. Panik Butonlarını Test Et
   ```
5. Seçtiğiniz teste göre ilgili sensörleri veya butonları kullanarak sistemi test edin
6. Serial Monitor'de sonuçları gözlemleyin
7. Telegram bildirimleri ve LED/Buzzer tepkilerini kontrol edin

## 📋 Test Kontrol Listesi

| Test Adımı | Beklenen Sonuç | Kontrol |
|------------|----------------|---------|
| Yangın Sensörü | Alev algılandığında kırmızı LED yanar ve bildirim gönderilir | □ |
| Gaz Sensörü | Gaz seviyesi eşiği aştığında buzzer çalar ve bildirim gönderilir | □ |
| Su Seviyesi | Kritik su seviyesinde alarm çalar ve bildirim gönderilir | □ |
| Deprem Algılama | Yeterli şiddette titreşimde alarm çalar ve bildirim gönderilir | □ |
| Panik Butonları | Butona basıldığında alarm çalar ve acil durum bildirimi gönderilir | □ |
| Telegram Bot | Komutlara doğru yanıt verir ve bildirimler iletilir | □ |
| LED Göstergeler | Farklı durumlarda doğru renklerde yanar | □ |
| Buzzer | Alarm durumlarında sesli uyarı verir | □ |

<div align="center">
  <h2>🚀 Güvenli Testler!</h2>
  <img src="https://media.giphy.com/media/VDGKJDJT64O5cHttaU/giphy.gif" alt="Güvenli Testler" width="200" />
</div>
