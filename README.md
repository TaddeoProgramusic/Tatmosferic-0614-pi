# IoT Weather Station with ESP32

This project implements an IoT weather station based on an ESP32, capable of measuring temperature, humidity, and ambient light levels. The data are collected via sensors connected to the microcontroller and can be sent to the cloud or displayed locally.

---

## Required Components

- ESP32 (development board)
- DHT11 (temperature and humidity sensor)
- LDR (light-dependent resistor for ambient light)
- 10KΩ resistor (to form a voltage divider with the LDR)
- Jumper wires (for connections)

---

## Network Requirement

This project requires access to an existing Wi‑Fi network.  
The ESP32 does not create its own access point in this implementation; instead, it connects to your local Wi‑Fi to send data.

---

## Data Collected

- Temperature (°C) → DHT11  
- Relative Humidity (%) → DHT11  
- Light Level (analogue value) → LDR + voltage divider  

Data can be displayed in the Serial Monitor or sent to an IoT server (e.g. MQTT, ThingSpeak, Node‑RED).

---

## Google Sheets Integration

The repository includes a file named `Script.gs`.  
This script is intended to be used in Google Apps Script within Google Sheets, allowing you to log and visualise the sensor data directly in a spreadsheet.

---

