
Arduino Morse Code Buzzer

A simple Arduino project that uses a buzzer to play Morse code signals.
This project currently plays the name "ADITYA" in Morse code using an active buzzer connected to an Arduino board.

Components Required
Arduino UNO/Nano
Active Buzzer
Jumper Wires
Breadboard (optional)
Circuit Connection
Buzzer Pin	Arduino Pin
Positive (+)	D3
Negative (-)	GND
Morse Code Used
Letter	Morse Code
A	.-
D	-..
I	..
T	-
Y	-.--
A	.-
Features
Generates Morse code using buzzer beeps
Uses different timing for dots and dashes
Beginner-friendly Arduino project
Easy to modify for custom names or messages
Arduino Code
int buzzer = 3 ; 

int dot = 200 ; 
int dash = 600 ; 

void setup() {
  
  pinMode(buzzer , OUTPUT);

}

void loop() {

  // A = .-
  
  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(600);


  // D = -..

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(600);


  // I = ..

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(600);


  // T = -

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(600);


  // Y = -.--

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(600);


  // A = .-

  digitalWrite(buzzer , HIGH);
  delay(dot);

  digitalWrite(buzzer , LOW);
  delay(dot);

  digitalWrite(buzzer , HIGH);
  delay(dash);

  digitalWrite(buzzer , LOW);
  delay(3000);

}
Future Improvements
Take user input from Serial Monitor
Convert any text into Morse code automatically
Add LED Morse signaling
Add LCD display support
Author

Aditya Prashant Maindargi
