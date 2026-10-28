# Nerf Controller 🎮
What if a Nerf blaster could double as a game controller?
linkedin link of the video:https://www.linkedin.com/posts/devi-hasini-desharaju-002739402_kinda-chic-to-be-building-our-first-hardware-activity-7497201221166931968-Yx6z?utm_source=share&utm_medium=member_ios&rcm=ACoAAGb648IBPxfaFsIzI97NsbOv05MiEkGNYSQ
This project started as an experiment to turn a physical Nerf blaster into an interactive controller using an ESP32 and a few sensors. The idea was to make the blaster respond to movement and physical inputs instead of just sitting there looking cool.
## What it does
The ESP32 collects different inputs from the controller and gives immediate feedback:

- MPU6050 for motion and orientation data
- Push buttons for forward/backward controls
- Piezo sensor for detecting impacts
- LEDs for visual feedback
- Buzzer for audio feedback
- Serial Monitor for viewing sensor readings
## Hardware
- ESP32 DevKit
- MPU6050
- Piezo sensor
- Push buttons
- LEDs
- Buzzer
- Breadboard
- Jumper wires
## How it works
The ESP32 continuously reads the sensors.
The MPU6050 provides acceleration data, the buttons act as movement inputs, and the piezo sensor detects a physical impact. Depending on the input, the controller responds through the LEDs and buzzer while printing the sensor values to the Serial Monitor.

## Tech
**Arduino IDE · C++ · ESP32 · I2C**
## Current status
**Working prototype**
The basic sensing and feedback system is working. The next step is connecting the controller to a computer/game and mapping the physical inputs to actual game actions.
## Code
The main Arduino sketch is:

`nerf_controller.ino`
## Why we built it
I wanted to experiment with the idea of taking something physical and turning it into a different kind of interface. It was also a fun way to learn how sensors, microcontrollers, and software can work together.

## 🔌 ESP32 Pin Configuration

The controller uses an ESP32 DevKit with the following GPIO connections.

| Component | ESP32 GPIO |
|-----------|------------|
| Red LED | GPIO 33 |
| Blue LED | GPIO 25 |
| Yellow LED | GPIO 27 |
| Buzzer | GPIO 26 |
| Forward Button | GPIO 18 |
| Backward Button | GPIO 19 |
| Piezo Sensor | GPIO 34 |
| MPU6050 SDA | GPIO 21 |
| MPU6050 SCL | GPIO 22 |

The MPU6050 communicates using I2C at address `0x68`.

Both push buttons use the ESP32's internal pull-up resistors and are active LOW.

## 🚀 Getting Started

1. Install Arduino IDE.
2. Install ESP32 board support through Boards Manager.
3. Connect the ESP32 to your computer using a USB data cable.
4. Open `nerf_controller.ino` in Arduino IDE.
5. Select your ESP32 board and its serial port.
6. Upload the sketch to the ESP32.
7. Open Serial Monitor at 115200 baud.
8. Move the controller, press the buttons, and test the piezo sensor to observe the readings and feedback.

## 📟 Serial Monitor

The controller prints accelerometer readings, piezo sensor values, and button status to the Serial Monitor.

This helps verify that the connected sensors and controls are responding correctly.

