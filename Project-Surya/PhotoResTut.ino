int photo = A4;
int Red = 11;
int Green = 3;
int buzzer = 8;

int Light;

void setup() {

  pinMode(photo, INPUT);

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Light = analogRead(photo);

  Serial.println(Light);

  delay(500);

  // Less sunlight
  if (Light > 0 && Light <= 600) {

    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
    digitalWrite(buzzer, LOW);
  }

  // Strong sunlight
  if (Light > 600) {

    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
    digitalWrite(buzzer, HIGH);
  }
}