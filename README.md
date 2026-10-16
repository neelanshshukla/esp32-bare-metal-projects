# ESP32 Bare-Metal Projects

A collection of embedded systems projects built on the ESP32 DevKit (30-pin) using C++ and the Arduino framework. 

These projects focus on exploring the **built-in hardware capabilities** of the ESP32 (WiFi, Bluetooth, Temperature, Hall Effect) without requiring any external sensors or components.

## 🛠️ Hardware Used
- **Board:** ESP32 DevKit V1 (30-pin)
- **Connection:** Micro-USB / USB-C to PC
- **Power:** USB (5V)

## 💻 Software Used
- **Language:** C++ (Arduino Framework)
- **IDE:** Arduino IDE / VS Code (PlatformIO)
- **Drivers:** CP2102 / CH340 (depending on the board)

## 📂 Project List

| # | Project Name | Description | Concepts Learned |
|---|--------------|-------------|------------------|
| 01 | `01_blink` | Blinks the onboard LED. | GPIO output, `delay()` |
| 02 | `02_button` | Reads the state of the onboard BOOT button. | GPIO input, `digitalRead()` |
| 03 | `03_temp_sensor` | Reads the internal temperature of the ESP32 processor. | ADC (Analog-to-Digital Converter) |
| 04 | `04_wifi_scanner` | Scans and lists nearby WiFi networks. | WiFi library, Serial Monitor |
| 05 | `05_ble_scanner` | Scans for nearby Bluetooth Low Energy devices. | BLE library, MAC addresses |
| 06 | `06_web_server` | Turns the ESP32 into a WiFi access point with a web UI to control the LED. | WiFi AP mode, HTTP, HTML/CSS integration |
