# Crash Black Box Recorder

A production-inspired embedded firmware project that continuously monitors an ESP32, records critical runtime diagnostics, preserves system information across resets using Non-Volatile Storage (NVS), and visualizes device health through a web dashboard.

The project is designed to emulate the diagnostic and fault logging mechanisms commonly found in industrial embedded systems, IoT gateways, automotive ECUs, and edge devices.

---

# Overview

Unexpected resets caused by watchdog timeouts, software faults, brownouts, or power failures can make debugging embedded systems extremely difficult. Production devices often include a "black box" that records important diagnostic information before or during recovery so engineers can determine what happened.

Crash Black Box Recorder recreates this concept on an ESP32 by continuously collecting runtime information, storing the latest device state in persistent memory, and later transmitting this information to a backend for visualization and analysis.

The primary focus of this project is software architecture, modular firmware design, and engineering practices rather than sensor interfacing.

---

# Objectives

* Build production-oriented embedded firmware
* Practice modular software architecture
* Implement persistent diagnostic storage
* Recover previous system state after reboot
* Build reusable embedded firmware modules
* Develop embedded-to-cloud communication
* Create a real-time monitoring dashboard

---

# Features

### Firmware

* Device diagnostics
* Reset reason detection
* Heap monitoring
* Uptime monitoring
* CPU frequency monitoring
* Wi-Fi RSSI monitoring
* Restart counter
* Persistent crash storage (NVS)
* Modular firmware architecture

### Backend

* REST API
* Device telemetry endpoint
* Crash report endpoint
* MongoDB integration

### Dashboard

* Live device monitoring
* Previous crash report
* Crash history
* Device information
* Runtime statistics

---

# Project Structure

```text
CrashBlackBoxRecorder/
│
├── include/
│   ├── diagnostics.h
│   ├── storage.h
│   ├── wifi_manager.h
│   └── api_client.h
│
├── src/
│   ├── main.cpp
│   ├── diagnostics.cpp
│   ├── storage.cpp
│   ├── wifi_manager.cpp
│   └── api_client.cpp
│
├── backend/
│   ├── server.js
│   ├── package.json
│   ├── routes/
│   ├── controllers/
│   └── models/
│
├── dashboard/
│   ├── src/
│   ├── public/
│   └── package.json
│
├── docs/
│   ├── architecture.png
│   ├── firmware-flow.png
│   └── dashboard.png
│
├── images/
│   ├── serial-monitor.png
│   ├── dashboard.png
│   └── esp32-setup.jpg
│
├── test/
│
├── platformio.ini
├── README.md
└── LICENSE
```

---

# System Architecture

```text
                            React Dashboard
                                   │
                                   │ HTTP
                                   ▼
                         Node.js / Express API
                                   │
                                   │
                          REST Communication
                                   │
                      Wi-Fi         │
                                   ▼
+----------------------------------------------------------+
|                         ESP32                            |
|                                                          |
|                +----------------------+                  |
|                |      main.cpp        |                  |
|                +----------+-----------+                  |
|                           │                              |
|        ┌──────────────────┼──────────────────┐           |
|        │                  │                  │           |
|        ▼                  ▼                  ▼           |
|  Diagnostics         Storage          WiFi Manager       |
|        │                  │                  │           |
|        └──────────────────┴──────────────────┘           |
|                           │                              |
|                           ▼                              |
|                     API Client                           |
+----------------------------------------------------------+
                           │
                           ▼
                  ESP32 Non-Volatile Storage
```

---

# Firmware Flow

```text
Power On
   │
   ▼
Initialize Serial
   │
   ▼
Initialize Diagnostics
   │
   ▼
Initialize Storage
   │
   ▼
Load Previous Crash Report
   │
   ▼
Increment Restart Counter
   │
   ▼
Initialize Wi-Fi
   │
   ▼
Connect to Backend
   │
   ▼
─────────────────────────────────────
            Main Loop
─────────────────────────────────────
   │
   ├── Read Device Diagnostics
   │
   ├── Update Crash Record
   │
   ├── Store Latest Status
   │
   ├── Send Live Telemetry
   │
   ├── Receive Server Response
   │
   └── Repeat
```

---

# Firmware Modules

## Diagnostics

Collects runtime information from the ESP32.

Responsibilities:

* Read reset reason
* Monitor free heap
* Monitor uptime
* Read CPU frequency
* Monitor Wi-Fi signal strength
* Provide device information

---

## Storage

Manages persistent data using ESP32 Non-Volatile Storage (NVS).

Responsibilities:

* Save crash report
* Load previous crash report
* Maintain restart counter
* Preserve diagnostic information across resets

---

## WiFi Manager

Handles wireless connectivity.

Responsibilities:

* Connect to Wi-Fi
* Automatic reconnection
* Connection monitoring
* Network status reporting

---

## API Client

Handles communication with the backend server.

Responsibilities:

* Send live telemetry
* Upload crash reports
* Receive server responses
* Manage HTTP communication

---

# Dashboard

The web dashboard will provide:

* Device connection status
* Firmware version
* CPU frequency
* Free heap
* Uptime
* Wi-Fi signal strength
* Restart counter
* Previous crash report
* Crash history
* Live telemetry

---

# Technologies

### Hardware

* ESP32 Dev Module

### Languages

* C++
* JavaScript

### Embedded Development

* PlatformIO
* Arduino Framework

### Backend

* Node.js
* Express.js

### Database

* MongoDB

### Frontend

* React
* Vite

---

# Current Status

* ✅ Diagnostics Module
* ✅ Storage Module
* ✅ Persistent Crash Recovery
* ✅ Restart Counter
* ⏳ WiFi Manager
* ⏳ API Client
* ⏳ Backend
* ⏳ Dashboard

---

# Future Improvements

* MQTT support
* OTA firmware updates
* NTP time synchronization
* Crash timestamps
* Multiple device support
* Authentication
* Docker deployment
* Historical analytics
* Flash write optimization
* SD card logging
* Power monitoring
* Brownout detection
* Unit testing
* CI/CD pipeline

---

# License

This project is licensed under the MIT License.

---

# Author

**Sushant Kumar Khobian**

Computer Engineering (IoT, Blockchain & Cyber Security)

Embedded Systems • Firmware • IoT • Robotics
