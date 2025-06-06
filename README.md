***Motion Fault Logger***

*Project Description*

This is an embedded system project for real-time motion fault detection using the TI MSP432E401Y microcontroller and the MPU-6050 IMU sensor. The system reads motion data over I2C and logs information via UART in CSV or JSON format. It is designed for applications requiring motion anomaly detection such as robotics, wearable devices, and safety-critical systems.

*Features*

Real-time accelerometer and gyroscope data acquisition
I2C communication with MPU-6050
UART-based data output to terminal
Basic fault detection capability
Code structured for integration with Power BI or Python dashboard tools
Developed using Keil uVision 5 and TI SimpleLink DriverLib
Project Structure

motion_fault_logger
    KeilProject/ – Keil uVision project files
    src/ – Source code files
        main.c
        i2c.c
        uart.c
        mpu6050.c (planned)
    include/ – Header files
        i2c.h
        uart.h
        mpu6050.h
    README.md
    .gitignore

**Getting Started**

*Prerequisites*
Keil MDK v5
SimpleLink MSP432E4 SDK
MSP432E401Y LaunchPad
MPU-6050 IMU sensor module
UART terminal software (e.g., PuTTY, TeraTerm)
Build Instructions
Clone the repository and open the .uvprojx file in Keil uVision.
Configure include paths to point to the installed SimpleLink SDK.
Connect the MSP432E401Y board via USB.
Build and flash the project using Keil.
Open a serial terminal (baud rate 115200) to view output.
Development Roadmap

*UART and I2C peripheral initialization*
MPU-6050 sensor wakeup and identity verification
Real-time sensor data acquisition
CSV or JSON serial output
Basic fault detection implementation
Python CLI data viewer (planned)
Power BI integration (planned)
Edge ML inference (planned)
Author

Kasra Noyan
B.Eng. Computer Engineering
McMaster University
GitHub: kasra-n34
LinkedIn: linkedin.com/in/kasranoyan
