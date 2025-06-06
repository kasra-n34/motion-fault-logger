Motion Fault Logger

Embedded System for Real-Time Motion Fault Detection using MSP432E401Y + MPU-6050

Project Description

This project is an embedded motion fault detection system built using the TI MSP432E401Y microcontroller and the MPU-6050 IMU sensor. It reads real-time motion data over I2C and logs abnormalities via UART in CSV or JSON format. The system is intended to help detect faulty or unexpected movement patterns for robotics, safety, or wearable systems.


✅ Features

Real-time accelerometer and gyroscope data acquisition
I2C communication with MPU-6050 (0x68)
UART-based data output to terminal (CSV or JSON-ready format)
Fault detection logic (basic thresholds or future ML)
Compatible with Power BI / Python data dashboard (planned)
Built using Keil uVision 5 + TI SimpleLink SDK DriverLib

📦 Project Structure

motion_fault_logger/
├── KeilProject/           # Keil uVision project files
├── src/
│   ├── main.c             # Main application logic
│   ├── i2c.c              # I2C driver
│   ├── uart.c             # UART logging
│   ├── mpu6050.c          # Sensor utilities (coming soon)
├── include/
│   ├── i2c.h
│   ├── uart.h
│   ├── mpu6050.h
├── README.md
└── .gitignore


⚙️ Getting Started

Prerequisites
Keil MDK v5
SimpleLink MSP432E4 SDK
MSP432E401Y LaunchPad
MPU-6050 sensor module
USB-to-Serial terminal (TeraTerm, PuTTY, etc.)
Build Instructions
Open the .uvprojx file in Keil uVision.
Ensure correct SDK paths are set under project options.
Build and flash to target board.
Open serial terminal (e.g., 115200 baud, 8N1) to view live logs.


🚀 Roadmap

 UART + I2C communication setup
 MPU-6050 device wakeup & WHO_AM_I check
 Sensor data reading & parsing
 CSV or JSON output logging
 Fault detection algorithm
 Python CLI dashboard
 Optional Power BI visualization
 TinyML deployment (Edge Impulse or TFLite)

 
👤 Author

Kasra Noyan
Computer Engineering, McMaster University
GitHub | LinkedIn
