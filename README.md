# nodemcu-ESP8266

**A collection of ESP8266 (NodeMCU / Wemos D1 Mini) example sketches, sensor codes, USB drivers and libraries.**
**مجموعه‌ای از کدهای نمونه، سنسورها، درایورهای USB و کتابخانه‌ها برای ESP8266 (NodeMCU / Wemos D1 Mini).**

---

## 🇬🇧 English

This repository is a personal toolbox for working with ESP8266 boards (NodeMCU / Wemos D1 Mini): single-purpose example sketches for common sensors, a basic WiFi TCP client/server demo, Windows USB chipset drivers, and the Arduino libraries needed to compile everything.

### 📂 Repository Structure

```
├── code/
│   ├── pir.ino        # PIR motion sensor — LED status output
│   ├── mc38.ino       # MC-38 magnetic door/window sensor
│   ├── rfid.ino       # RC522 RFID reader — UID access check
│   └── wifi.ino       # Basic WiFi TCP client example
├── Wireless file transfer via WiFi /
│   ├── server.ino     # TCP server on ESP8266 (receives values, replies)
│   └── claint.ino     # TCP client (sends values to the server)
├── Chipset driver/
│   ├── CH341SER_WINDOWS.zip           # CH340/CH341 USB driver
│   └── CP210x_Universal_Windows_Driver.zip  # CP2102 USB driver
└── libraries-low.rar  # Required Arduino libraries (low version)
```

### 🧪 The Example Sketches

| Sketch | Sensor / Topic | How it works |
|---|---|---|
| `code/pir.ino` | PIR motion sensor | Reads the sensor on **D7**, switches a status LED on **D6** and prints motion state to Serial (115200 baud) |
| `code/mc38.ino` | MC-38 door/window contact | Reads the reed switch on **D1** (`INPUT_PULLUP`) and prints *open / closed* to Serial (9600 baud) |
| `code/rfid.ino` | MFRC522 RFID reader | Detects cards, reads the UID and checks it against known UIDs for access control. Full Wemos D1 Mini wiring is included in the comments |
| `code/wifi.ino` | WiFi TCP client | Joins your WiFi network and periodically exchanges messages with a server over TCP port 80 |
| `server.ino` / `claint.ino` | Two-board TCP demo | Client sends a number, server receives it, replies with another number — a minimal two-ESP8266 communication pattern |

### 🔧 Setup

1. **Add the ESP8266 board to the Arduino IDE** — paste this URL into *File → Preferences → Additional Board Manager URLs*:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
   Then install **esp8266** from *Boards Manager*.

2. **Install the USB driver** for your board from [`Chipset driver/`](Chipset%20driver) (CH341 for CH340-based boards, CP210x for CP2102-based boards).

3. **Install the libraries** — download and extract the `libraries-low.rar` archive (or the "Libraries high" package linked below) into your Arduino `libraries` folder.

### 📚 Libraries

- **Libraries (high)**: [MEGA download link](https://mega.nz/file/fwNVzYYI#HzTfbAew3lhpZ0_QaE-9Wo-yAZ8GUctxxr7TlpUMB3g)
- **Libraries (low)**: [`libraries-low.rar`](libraries-low.rar) in this repo

> 💡 Edit `ssid` / `password` in the WiFi sketches before uploading to your board.

---

## 🇮🇷 فارسی

این ریپازیتوری یک جعبه‌ابزار شخصی برای کار با بردهای ESP8266 (NodeMCU / Wemos D1 Mini) است: کدهای نمونه تک‌منظوره برای سنسورهای پرکاربرد، یک نمونه ارتباط TCP بین دو برد، درایورهای ویندوز چیپ USB و کتابخانه‌های لازم برای کامپایل.

### 🧪 کدهای نمونه

| کد | سنسور / موضوع | توضیح |
|---|---|---|
| `pir.ino` | سنسور حرکت PIR | خواندن سنسور روی **D7**، روشن/خاموش کردن LED روی **D6** و چاپ وضعیت روی سریال |
| `mc38.ino` | سنسور مغناطیسی درب MC-38 | خواندن سنسور روی **D1** و چاپ باز/بسته بودن درب روی سریال |
| `rfid.ino` | ماژول RFID RC522 | خواندن UID کارت و تطبیق با کارت‌های مجاز برای کنترل دسترسی. نقشه اتصال کامل داخل کامنت‌های کد |
| `wifi.ino` | کلاینت TCP | اتصال به وایرلس و تبادل پیام با یک سرور روی پورت ۸۰ |
| `server.ino` / `claint.ino` | ارتباط دو برد | کلاینت یک عدد می‌فرستد، سرور جواب می‌دهد — الگوی ساده ارتباط دو ESP8266 |

### 🔧 راه‌اندازی

1. **اضافه‌کردن برد ESP8266 به Arduino IDE** — این لینک را در *File → Preferences → Additional Board Manager URLs* بگذارید و از *Boards Manager* نصب کنید:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
2. **نصب درایور USB** مناسب بردتان از پوشه [`Chipset driver/`](Chipset%20driver) (CH341 یا CP210x).
3. **نصب کتابخانه‌ها** — فایل `libraries-low.rar` را در پوشه `libraries` آردوینو استخراج کنید.

> 💡 قبل از آپلود، مقدار `ssid` و `password` در کدهای وایرلس را ویرایش کنید.

---

## 📄 License

Example code is free to use and modify for personal and educational projects.
