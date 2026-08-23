# Nerf Controller 🎮
What if a Nerf blaster could double as a game controller?
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
