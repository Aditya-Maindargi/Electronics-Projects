#include<Servo.h>

int ServoPin = 9 ; // Always use PWM (~) pins for using Servo motor
int LDR = A0 ; 
int AnaToDeg ; 

Servo MyServo ;






void setup() {
  // put your setup code here, to run once:
  MyServo.attach(ServoPin);
  //pinMode(ServoPin , OUTPUT);
  pinMode(LDR , INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  AnaToDeg = (180./1023.)*analogRead(LDR)*4;
    Serial.println(AnaToDeg);
  MyServo.write(AnaToDeg);








}
