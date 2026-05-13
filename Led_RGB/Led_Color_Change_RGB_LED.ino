int Rpin = 11;
int Gpin = 6;
int Bpin = 3;

String shade;

void setup() {

  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Serial.println("Choose Pink Shade:");
  Serial.println("lightpink");
  Serial.println("hotpink");
  Serial.println("deeppink");
  Serial.println("rosepink");
  Serial.println("babypink");

  while (Serial.available() == 0) {

  }

  shade = Serial.readString();
  shade.trim();

  // LIGHT PINK
  if (shade == "lightpink") {

    analogWrite(Rpin, 255);
    analogWrite(Gpin, 182);
    analogWrite(Bpin, 193);

  }

  // HOT PINK
  else if (shade == "hotpink") {

    analogWrite(Rpin, 255);
    analogWrite(Gpin, 105);
    analogWrite(Bpin, 180);

  }

  // DEEP PINK
  else if (shade == "deeppink") {

    analogWrite(Rpin, 255);
    analogWrite(Gpin, 20);
    analogWrite(Bpin, 147);

  }

  // ROSE PINK
  else if (shade == "rosepink") {

    analogWrite(Rpin, 255);
    analogWrite(Gpin, 0);
    analogWrite(Bpin, 127);

  }

  // BABY PINK
  else if (shade == "babypink") {

    analogWrite(Rpin, 255);
    analogWrite(Gpin, 192);
    analogWrite(Bpin, 203);

  }

  else {

    Serial.println("Invalid Shade");

  }

  delay(500);
}