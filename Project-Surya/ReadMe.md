# ☀️ SunBuzz – Arduino Sunlight Alert System

A smart Arduino-based sunlight detection system using an LDR sensor module, LEDs, and a buzzer.

This project helps detect strong sunlight conditions and alerts the user when clothes can be dried outside after cloudy or rainy weather.

---

## 🚀 Features

- Detects sunlight intensity using LDR sensor
- Green LED indicates low sunlight / cloudy conditions
- Red LED indicates strong sunlight
- Buzzer alert when sunlight becomes strong
- Real-time light monitoring using Serial Monitor

---

## 🛠️ Components Used

- Arduino UNO
- LDR Sensor Module
- Red LED
- Green LED
- Buzzer
- Resistors
- Jumper Wires
- Breadboard

---

## ⚡ Circuit Connections

### LDR Module
| LDR Module Pin | Arduino Pin |
|----------------|-------------|
| VCC            | 5V          |
| GND            | GND         |
| AO             | A4          |

### LEDs
| Component | Arduino Pin |
|-----------|--------------|
| Red LED   | D11          |
| Green LED | D3           |

### Buzzer
| Component | Arduino Pin |
|-----------|--------------|
| Buzzer    | D8           |

---

## 🧠 Working Principle

- The LDR sensor reads surrounding light intensity.
- Arduino continuously monitors the analog values.
- When sunlight intensity crosses a threshold:
  - Red LED turns ON
  - Buzzer activates
- During low-light conditions:
  - Green LED remains ON

This can be useful as a simple clothes-drying sunlight indicator.

---

## 💻 Arduino Code

```cpp
int photo = A4;

int Red = 11;
int Green = 3;
int buzzer = 8;

int Light;

void setup() {

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Light = analogRead(photo);

  Serial.println(Light);

  if (Light > 700) {

    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);

    tone(buzzer, 1000);
    delay(200);

    noTone(buzzer);
    delay(200);
  }

  else {

    digitalWrite(Red, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(300);
}
