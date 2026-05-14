int buzzerPin = 3;

// Morse timing
int dotTime = 200;
int dashTime = dotTime * 3;
int symbolGap = dotTime;
int letterGap = dotTime * 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  // A = .-
  dot();
  dash();
  delay(letterGap);

  // D = -..
  dash();
  dot();
  dot();
  delay(letterGap);

  // I = ..
  dot();
  dot();
  delay(letterGap);

  // T = -
  dash();
  delay(letterGap);

  // Y = -.--
  dash();
  dot();
  dash();
  dash();
  delay(letterGap);

  // A = .-
  dot();
  dash();
  delay(letterGap);

  // repeat gap
  delay(3000);
}

void dot() {
  digitalWrite(buzzerPin, HIGH);
  delay(dotTime);

  digitalWrite(buzzerPin, LOW);
  delay(symbolGap);
}

void dash() {
  digitalWrite(buzzerPin, HIGH);
  delay(dashTime);

  digitalWrite(buzzerPin, LOW);
  delay(symbolGap);
}