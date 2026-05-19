#include<Servo.h>

Servo myServo1 ; 
Servo myServo2 ; 

int ServoPin1 = 11 ;
int ServoPin2 = 9 ; 

int Xaxis = A0 ; 
int Yaxis = A5 ; 

int ServoMove1 ; 
int ServoMove2 ; 

int Xval ; 
int Yval ; 

void setup() {

  myServo1.attach(ServoPin1);
  myServo2.attach(ServoPin2);

  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);

  Serial.begin(9600);

}

void loop() {

  Xval = analogRead(Xaxis);
  Yval = analogRead(Yaxis);

  ServoMove1 = (180.0 / 1023.0) * Xval;
  ServoMove2 = (180.0 / 1023.0) * Yval;

  Serial.print("X Axis Val = ");
  Serial.println(Xval);

  Serial.print("Y Axis Val = ");
  Serial.println(Yval);

  Serial.print("Servo 1 Degree = ");
  Serial.println(ServoMove1);

  Serial.print("Servo 2 Degree = ");
  Serial.println(ServoMove2);

  myServo1.write(ServoMove1);
  myServo2.write(ServoMove2);

  delay(50);

}