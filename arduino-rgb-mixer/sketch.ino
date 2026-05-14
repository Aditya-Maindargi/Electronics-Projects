 // RGB pins variable :
int Rpin = 11;
int Gpin = 6;
int Bpin = 3;

// Potentiometer pins :
int R_pot = A3;
int G_pot = A4;
int B_pot = A5;

// Potentiometer values :
int Red;
int Green;
int Blue;

void setup() {

  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Red = (255.0 / 1023.0) * analogRead(R_pot);
  Green = (255.0 / 1023.0) * analogRead(G_pot);
  Blue = (255.0 / 1023.0) * analogRead(B_pot);

  Serial.print("Red : ");
  Serial.println(Red);

  Serial.print("Green : ");
  Serial.println(Green);

  Serial.print("Blue : ");
  Serial.println(Blue);

  analogWrite(Rpin, Red);
  analogWrite(Gpin, Green);
  analogWrite(Bpin, Blue);

  delay(200);
}