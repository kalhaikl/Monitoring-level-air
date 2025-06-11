# 💧 IoT Monitoring Level Air dengan ESP32 + Blynk

Proyek ini adalah sistem **monitoring level air otomatis berbasis IoT** yang menggunakan **ESP32**, **sensor ultrasonik**, **relay**, dan **pompa air**. Sistem ini memungkinkan pengguna untuk memantau ketinggian air **secara real-time melalui aplikasi Blynk**, dan secara otomatis mengaktifkan pompa jika air di bawah ambang batas tertentu.

## 📲 Fitur Utama

- 🌐 Monitoring ketinggian air secara real-time via **Blynk App**
- ⚡ Pengendalian pompa air otomatis menggunakan **relay**
- 🚨 Notifikasi visual pada aplikasi saat air mencapai batas minimum
- 🔧 Mudah dipasang dan dikonfigurasi

## 🔧 Komponen yang Digunakan

| Komponen           | Deskripsi                         |
|--------------------|----------------------------------|
| ESP32              | Mikrokontroler dengan Wi-Fi       |
| Sensor Ultrasonik  | HC-SR04 untuk mengukur level air  |
| Relay              | Mengendalikan pompa air           |
| Pompa Air          | Untuk mengisi ulang tangki        |
| Blynk IoT Platform | Monitoring dan kontrol via HP     |

## ⚙️ Skema Koneksi

| Komponen           | ESP32 Pin     |
|--------------------|---------------|
| Trig Sensor        | GPIO 14       |
| Echo Sensor        | GPIO 27       |
| Relay Modul        | GPIO 4        |

## 📲 Instalasi & Setup

1. **Clone repositori ini** ke komputer kamu:
   ```bash
   git clone https://github.com/kalhaikl/Monitoring-level-air.git
2. Buka file main.ino di Arduino IDE

3. Install library yang dibutuhkan:
   - Blynk (versi terbaru)
   - WiFi (untuk ESP32)

4. Hubungkan ESP32 ke komputer, lalu atur parameter Wi-Fi dan token Blynk di dalam kode
5. Upload kode ke ESP32, dan buka Blynk App untuk mulai monitoring level air secara live!
