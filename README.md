<div align="center">
  
# AdliMudahele
**Digital Forensics & Incident Response (DFIR) First-Response Tool**<br>
**Dijital Adli Bilişim ve Olay Müdahalesi (DFIR) İlk Müdahale Aracı**

![Ubuntu](https://img.shields.io/badge/OS-Ubuntu%20%7C%20Linux-orange?style=for-the-badge&logo=ubuntu)
![C++](https://img.shields.io/badge/Backend-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Python](https://img.shields.io/badge/Frontend-Python-3776AB?style=for-the-badge&logo=python)

</div>

---

## English Description

### About The Project
**AdliMudahele** is a purpose-built DFIR first-response triage tool for Linux (Ubuntu) environments. When a cyber incident occurs (e.g., suspected malware, unauthorized access, or data exfiltration), investigators need an immediate snapshot of the system's volatile state without destroying the evidence. By leveraging a low-level **C++ engine** for data extraction and a **Python (Tkinter) GUI** for a Matrix-themed presentation, this tool allows for rapid, secure, and read-only analysis of the system.

### Key Features
*  **Live Network Forensics:** Identifies active connections, open ports, and associated processes (PID) to detect unauthorized data exfiltration or C2 communications.
*  **Persistence Detection:** Scans scheduled tasks (`cron` jobs) to uncover hidden malware persistence mechanisms.
*  **Volatile Memory (RAM) Analysis:** Isolates and lists processes consuming the highest memory, helping to identify fileless malware.
*  **Browser Phishing Analysis:** Safely extracts recent Firefox browsing history (supporting both Snap and classic `.deb` installations) by bypassing SQLite database locks.
*  **USB Exfiltration Tracking:** Parses kernel logs (`dmesg`) to identify recently connected USB storage devices (Manufacturer, Product, and Serial Number).
*  **Cryptographic Sealing:** Automatically exports forensic findings into a timestamped text report and generates an accompanying **SHA-256 hash seal** to cryptographically prove chain of custody.

---

##  Türkçe Açıklama

###  Proje Hakkında
**AdliMudahele**, Linux (Ubuntu) ortamları için özel olarak geliştirilmiş bir DFIR ilk müdahale (triage) aracıdır. Bir siber olay meydana geldiğinde (şüpheli zararlı yazılım, yetkisiz erişim veya veri sızıntısı gibi), adli bilişim uzmanlarının delilleri yok etmeden sistemin uçucu durumunun anlık bir görüntüsüne ihtiyacı olur. Veri çıkarma işlemi için düşük seviyeli bir **C++ motoru** ve görsel sunum için Matrix temalı bir **Python (Tkinter) arayüzü** kullanan bu araç, sistemin hızlı, güvenli ve salt okunur analizi edilmesini sağlar.

###  Temel Özellikler
*  **Canlı Ağ Analizi:** Yetkisiz veri sızıntılarını veya C2 (Komuta Kontrol) haberleşmelerini tespit etmek için aktif bağlantıları, açık portları ve ilişkili süreçleri (PID) tanımlar.
*  **Kalıcılık Tespiti:** Gizli zararlı yazılım kalıcılık mekanizmalarını ortaya çıkarmak için zamanlanmış görevleri (`cron` görevleri) tarar.
*  **Uçucu Bellek (RAM) Analizi:** Dosyasız (fileless) zararlı yazılımların tespit edilmesine yardımcı olmak için en yüksek belleği tüketen süreçleri izole eder ve listeler.
*  **Tarayıcı Oltalama Analizi:** SQLite veritabanı kilitlerini atlatarak son Firefox gezinme geçmişini (hem Snap hem de klasik `.deb` kurulumlarını destekler) güvenli bir şekilde çıkarır.
*  **USB Veri Sızıntısı Takibi:** Yetkisiz veri hırsızlığını ve içeriden gelen tehditleri tespit etmek için çekirdek günlüklerini (`dmesg`) ayrıştırarak son bağlanan USB depolama aygıtlarını (Üretici, Ürün ve Seri Numarası) tanımlar.
*  **Kriptografik Mühürleme:** Adli bilişim bulgularını otomatik olarak zaman damgalı bir metin raporuna aktarır ve delil bütünlüğünü kriptografik olarak kanıtlamak için rapora ait bir **SHA-256 hash mührü** oluşturur.

---

## Prerequisites / Gereksinimler

Before running the tool, ensure you have the necessary compilers and libraries installed on your Ubuntu system: / *Aracı çalıştırmadan önce, Ubuntu sisteminizde gerekli derleyici ve kütüphanelerin kurulu olduğundan emin olun:*

```bash
sudo apt update
sudo apt install g++ cmake sqlite3 python3-tk -y
```

---

## Installation & Usage / Kurulum ve Kullanım

1. **Clone the repository / *Depoyu klonlayın*:**
   ```bash
   git clone https://github.com/cagatay005/AdliMudahele.git
   cd AdliMudahele
   ```

2. **Grant execution permissions / *Çalıştırma izinlerini tanımlayın*:**
   ```bash
   chmod +x calistir.sh
   ```

3. **Run the tool (Root privileges recommended for USB logs) / *Aracı çalıştırın (USB günlükleri için Root yetkisi önerilir)*:**
   ```bash
   sudo ./calistir.sh
   ```
   *The script will automatically compile the C++ backend using CMake and launch the Python GUI. / Betik, CMake kullanarak C++ arka planını otomatik olarak derleyecek ve Python arayüzünü başlatacaktır.*

---

## Project Architecture / Proje Mimarisi

```text
AdliMudahele/
├── bin/                 # Compiled C++ executable / Derlenmiş C++ motoru
├── core/                # C++ Backend Engine (Heavy Lifting) / C++ Arka Plan Motoru
│   ├── include/         # Header (.h) files / Başlık dosyaları
│   └── src/             # Source (.cpp) files / Kaynak dosyaları
├── gui/                 # Python Frontend / Python Arayüzü
│   └── arayuz.py        # Tkinter Matrix UI / Tkinter Arayüz Kodu
├── veri/                # Exported Forensics Reports & SHA-256 Seals / Raporlar ve Mühürler
├── CMakeLists.txt       # Build configuration / Derleme yapılandırması
└── calistir.sh          # Automation & Execution script / Otomasyon betiği
```

---

## Chain of Custody & Verification / Delil Bütünlüğü ve Doğrulama

**EN:** When the **"RAPORU KAYDET VE MUHURLE"** button is clicked within the GUI, the tool outputs two files into the `veri/` directory: `delil.txt` (raw report) and `delil.sha256` (hash seal). To verify evidence integrity, run:

**TR:** Arayüz içerisindeki **"RAPORU KAYDET VE MUHURLE"** butonuna tıklandığında, araç `veri/` dizinine iki dosya çıkartır: `delil.txt` (ham rapor) ve `delil.sha256` (hash mührü). Delil bütünlüğünü doğrulamak için şu komutu çalıştırın:

```bash
cd veri
sha256sum -c delil.sha256
```
*(Expected Output / Beklenen Çıktı: `delil.txt: OK`)*

---

## Disclaimer / Feragatname
*This tool is developed for educational and professional Digital Forensics and Incident Response (DFIR) purposes. The developer is not responsible for any misuse of this software. / Bu araç adli bilişim ve olay müdahalesi (DFIR) alanında eğitim ve profesyonel kullanım amacıyla geliştirilmiştir. Yazılımın kötüye kullanımından geliştirici sorumlu tutulamaz.*
