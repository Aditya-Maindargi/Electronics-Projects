RGB LED Controller using Arduino

Control an RGB LED using three potentiometers with an Arduino Uno.
Each potentiometer independently controls the intensity of the Red, Green, and Blue channels using PWM.

Features
Real-time RGB color mixing
PWM brightness control
Analog input handling
Simple embedded systems project
Beginner-friendly hardware setup
Components Used
Arduino Uno
RGB LED (Common Cathode)
3 × 220Ω Resistors
3 × Potentiometers
Breadboard
Jumper wires
Circuit Connections
RGB LED Connections
RGB Pin	Arduino Pin
Red	11
Green	6
Blue	3
Common Cathode	GND
Potentiometer Connections
Potentiometer	Arduino Analog Pin
Red Control	A3
Green Control	A4
Blue Control	A5

All potentiometers share:

VCC → 5V
GND → GND
How It Works

The potentiometers act as analog input devices.

The Arduino:

Reads analog values from each potentiometer
Converts them into PWM signals
Adjusts RGB LED brightness accordingly

This creates dynamic color mixing in real time.

Concepts Used
PWM (Pulse Width Modulation)
Analog Input Reading
RGB Color Mixing
Embedded Systems Basics
Circuit Debugging
File Structure
.
├── sketch.ino
├── diagram.json
└── wokwi-project.txt
Simulation

Project created and tested on:

Wokwi Simulator

Project configuration files included.

Author

Aditya Prashant Maindargi
Manufacturing Engineering Student at College of Engineering Pune

License

This project is open-source and free to use for learning purposes
