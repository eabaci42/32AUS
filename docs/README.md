# <div align="center">📚 Dokümantasyon</div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0891b2&height=150&section=header&text=AUS%20Dokümantasyon&fontSize=40&fontColor=ffffff&animation=fadeIn&fontAlignY=38" alt="Dokümantasyon" />
</div>

<p align="center">
  <img src="https://media.giphy.com/media/l3q2Pb3RTnNrGCfmM/giphy.gif" alt="Dokümantasyon" width="200" />
  <br>
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=18&duration=2000&pause=500&color=0891B2&center=true&vCenter=true&width=450&lines=Teknik+Bilgiler;Sensör+Özellikleri;Devre+Şemaları;Kullanım+Kılavuzu;Kurulum+Talimatları" alt="Typing SVG" />
</p>

<div align="center">
  <a href="../README.md">
    <img src="https://img.shields.io/badge/Ana%20Sayfa-0891b2?style=for-the-badge" alt="Ana Sayfa" />
  </a>
</div>

## 📋 Genel Bakış
Bu klasör, Akıllı Ev ve Afet Uyarı Sistemi (AUS) projesinin dokümantasyonunu içerir. Sistem bileşenleri, devre şemaları, sensör özellikleri ve kullanım kılavuzları gibi tüm teknik belgeleri bulabilirsiniz.

## 📝 Dokümantasyon İçeriği

| Kategori | Açıklama |
|----------|----------|
| **Sensör Bilgileri** | Tüm sensörlerin teknik özellikleri, çalışma prensipleri, kalibrasyonları ve veri aralıkları |
| **Devre Şemaları** | ESP32 ve tüm bileşenlerin bağlantı şemaları, pin konfigürasyonları |
| **İletişim Protokolleri** | Telegram bot, e-posta, OTA güncellemesi için teknik detaylar |
| **Kullanıcı Kılavuzu** | Sistemin kurulumu, kullanımı ve bakımı için kapsamlı rehber |
| **Sorun Giderme** | Sık karşılaşılan sorunlar ve çözüm önerileri |

## 🛠️ Pin Bağlantı Şeması

| GPIO Pin | Tür | Sensör/Bileşen | Pins Dizisi | Renk |
|----------|-----|----------------|-------------|------|
| GPIO36 | Analog | Gas Sensor | Pins[0] | Sarı |
| GPIO23 | Digital | Flame Sensor | Pins[1] | Turuncu |
| GPIO18 | Digital | Ultrasonik Echo | Pins[2] | Mor |
| GPIO5 | Digital | Ultrasonik Trig | Pins[3] | Yeşil |
| GPIO3 | Digital | Nem & Sıcaklık DHT11 | Pins[4] | Sarı |
| GPIO15 | Digital | Panic Button Mobile | Pins[5] | Sarı |
| GPIO19 | Digital | Panic Button Home | Pins[6] | Mavi |
| GPIO13 | Analog | RGB Diyot Kırmızı | Pins[7] | Direct |
| GPIO12 | Analog | RGB Diyot Yeşil | Pins[8] | Direct |
| GPIO14 | Analog | RGB Diyot Mavi | Pins[9] | Direct |
| GPIO34 | Digital | Gas Sensor | Pins[10] | Yeşil |
| GPIO17 | Digital | Buzzer | Pins[11] | Sarı |
| GPIO16 | Digital | ResetFlood | Pins[12] | Sarı |

## 📡 Sensör Özellikleri

| Sensör | Model | Çalışma Voltajı | Veri Aralığı | Hassasiyet |
|--------|-------|-----------------|--------------|------------|
| Yangın Sensörü | Alev Sensörü | 3.3V-5V | Dijital (0-1) | 20-100 cm mesafe |
| Gaz Sensörü | MQ-2 | 5V | Analog (0-4095) | 300-10000 ppm |
| Ultrasonik Sensör | HC-SR04 | 5V | 2-400 cm | ±3mm |
| Sıcaklık/Nem | DHT11 | 3.3V-5V | 0-50°C, 20-90% | ±2°C, ±5% |
| İvmeölçer | ADXL345 | 3.3V | ±16g | 13-bit çözünürlük |

<div align="center">
  <h2>🚀 Güvenli Kullanım!</h2>
  <img src="https://media.giphy.com/media/3o6ZsXHLRnkgPtEYVi/giphy.gif" alt="Güvenli Kullanım" width="200" />
</div>
