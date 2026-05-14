Pink Shades RGB Controller using Arduino

A fun RGB LED project using an Arduino Uno that allows users to select different shades of pink through the Serial Monitor.

The Arduino reads user input from the Serial Monitor and changes the RGB LED color using PWM signals.

Features
Serial Monitor color selection
Multiple pink shades
PWM-based RGB control
Beginner-friendly Arduino project
Real-time LED color changing
Available Pink Shades
Light Pink
Hot Pink
Deep Pink
Rose Pink
Baby Pink
Components Used
Arduino Uno
RGB LED (Common Cathode)
3 × 220Ω Resistors
Breadboard
Jumper Wires
Pin Connections
RGB LED Pin	Arduino Pin
Red	11
Green	6
Blue	3
Common Cathode	GND
How It Works
The Arduino displays available pink shades in the Serial Monitor.
The user types a shade name.
The Arduino reads the input using Serial Communication.
PWM values are applied to the RGB LED using analogWrite().
The LED changes to the selected pink shade.
Example Inputs
lightpink
hotpink
deeppink
rosepink
babypink
Concepts Used
PWM (Pulse Width Modulation)
Serial Communication
RGB Color Mixing
Conditional Statements
User Input Handling
Code Highlights
Serial Input
shade = Serial.readString();
shade.trim();

Reads user input from the Serial Monitor and removes extra spaces/newlines.

RGB Color Control
analogWrite(Rpin, 255);
analogWrite(Gpin, 105);
analogWrite(Bpin, 180);

Controls LED intensity for each color channel to generate different shades of pink.

How to Run
Upload the code to the Arduino Uno.
Open Serial Monitor.
Set baud rate to 9600.
Type a pink shade name.
Watch the RGB LED change colors.
Future Improvements
Add more color categories
Smooth fade transitions
Bluetooth/mobile control
OLED display menu
Voice-controlled colors
Custom RGB input mode
Author

Aditya Prashant Maindargi
Manufacturing Engineering Student at College of Engineering Pune

License

Open-source project for learning and experimentation.
