#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Pot = A0;
int PotVal;

int Red = 11;
int Green = 10;
int Blue = 9;

int button = 8;
int button_input;

String Color[] = {"Red", "Green", "Blue"};

void red() {
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
}

void green() {
  digitalWrite(Red, LOW);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, LOW);
}

void blue() {
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, HIGH);
}

void Light() {



  if (PotVal <= 330) {
    red();
  }

  else if (PotVal <= 679) {
    green();
  }

  else {
    blue();
  }

}

void Light_off(){
    digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
}
void setup() {

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  pinMode(Pot, INPUT);
  pinMode(button, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {

  PotVal = analogRead(Pot);
  button_input = digitalRead(button);

  Serial.println(PotVal);

  lcd.clear();


  // RED SELECTED


  if (PotVal <= 330) {

    lcd.setCursor(0, 0);
    lcd.print(">");

    lcd.setCursor(3, 0);
    lcd.print(Color[0]);   // Red

    lcd.setCursor(3, 1);
    lcd.print(Color[1]);   // Green
  }



  else if (PotVal <= 580) {

    lcd.setCursor(0, 1);
    lcd.print(">");

    lcd.setCursor(3, 0);
    lcd.print(Color[0]);   // Green

    lcd.setCursor(3, 1);
    lcd.print(Color[1]);   // Blue
  }


  else if (PotVal <= 680) {

    lcd.setCursor(0, 0);
    lcd.print(">");

    lcd.setCursor(3, 0);
    lcd.print(Color[1]);   // Green

    lcd.setCursor(3, 1);
    lcd.print(Color[2]);   // Blue
  }
  // ======================
 

  else {

    lcd.setCursor(3, 0);
    lcd.print(Color[1]);   // Green

    lcd.setCursor(0, 1);
    lcd.print(">");

    lcd.setCursor(3, 1);
    lcd.print(Color[2]);   // Blue
  }

  if (button_input == 0) {
    Light();
  } 
  else if (button_input == 1){
    Light_off();
  }


  delay(150);
}