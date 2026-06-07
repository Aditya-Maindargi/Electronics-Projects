#include<Wire.h> 
#include<LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27 , 16,2);

int button = 8;
int Pot = A0;

int buttonVal;
int lastButtonVal = HIGH;
int counter = 0;
int PotVal;
bool messagePrinted = false;


int Red = 11 ; 
int Blue = 9 ; 
int Green = 10 ; 

int Red_Val;
int Green_Val;
int Blue_Val;


void onLED(){
  analogWrite(Red , Red_Val);
  analogWrite(Green , Green_Val);
  analogWrite(Blue , Blue_Val);  
} 

void offLED(){
  analogWrite(Red , 0);
  analogWrite(Green ,0);
  analogWrite(Blue , 0); 
}


int AnalogToDigital() {
  return map(analogRead(Pot), 0, 1023, 0, 255);
}

void Lcd_Update(int Val_color){
  String Color[] = {"Red" , "Green" , "Blue"};
  int Color_Counter = counter - 1 ;
    lcd.setCursor(1,0);
    lcd.print(Color[Color_Counter]);
    lcd.setCursor(0,1);
    lcd.print("Val :");
    lcd.setCursor(6,1);
    lcd.print("   ");
    lcd.setCursor(6,1);
    lcd.print(Val_color);
}

void Counter() {
  buttonVal = digitalRead(button);


  if (buttonVal == LOW && lastButtonVal == HIGH) {
    counter++;
    lcd.clear();
    Serial.print("Button pressed: ");
    Serial.println(counter);
    messagePrinted = false;
  }

  lastButtonVal = buttonVal;
  delay(100);
}

void setup() {

  pinMode(Red , OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);

  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Button press counter ready.");

  //  To initiate the LCD 
  lcd.init(); 
  lcd.backlight();

}

void loop() {
  Counter();
// This line let the Code initiate and give time to the user to know what i gonna happen next 
  if (counter == 0 && !messagePrinted) {
    lcd.clear();
    lcd.print("Button To Start");
   
    Serial.println("Press button to start. Use potentiometer to set PWM values.");
    messagePrinted = true;
  }


// THis line will present the change in Red led Pwm Value and store once the value is confirmed 
  else if (counter == 1) {
    Red_Val = AnalogToDigital();
    Serial.print("Red PWM Value: ");
    Serial.println(Red_Val);
    Lcd_Update(Red_Val);
    delay(200);
  }

// THis line will present the change in Green led Pwm Value and store once the value is confirmed 
  else if(counter == 2 ){
    Green_Val = AnalogToDigital();
    Serial.print("Green PWM Value: ");
    Serial.println(Green_Val);
    Lcd_Update(Green_Val);
    delay(200);   
  }

// THis line will present the change in Blue led Pwm Value and store once the value is confirmed 
  else if(counter == 3 ){
    Blue_Val = AnalogToDigital();
    Serial.print("Blue PWM Value: ");
    Serial.println(Blue_Val);
    Lcd_Update(Blue_Val);
    delay(200);   
  } 

// This line will show the user that what values they have selected and tell them that Now Led Will do this so 
  else if (counter == 4 && !messagePrinted) {  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R:"); lcd.print(Red_Val);
    lcd.print(" G:"); lcd.print(Green_Val);
    lcd.setCursor(0,1);
    lcd.print("B:"); lcd.print(Blue_Val);

    Serial.println("Red value locked in:");
    Serial.println(Red_Val);
    Serial.println("Green value locked in:");
    Serial.println(Green_Val);
    Serial.println("Blue value locked in:");
    Serial.println(Blue_Val);
    Serial.println("  ");
    Serial.println("To Reset the Color please press again ");
    messagePrinted = true;  
  } 

  else if (counter == 5 && !messagePrinted){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LED Animation");
    delay(500);

    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("Leds Will Blink") ;
    for (int i = 0 ; i<6 ; i++){
      onLED();
      delay(300);
      offLED();
      delay(300);
    }

    delay(500);

    lcd.clear();
    lcd.setCursor(0,0) ;
    lcd.print("Led COntinous Glow");
    onLED();
    delay(2500);
    offLED();
    delay(100);

    messagePrinted = true;
  }

// This line tells the user that this is the last click and then LCD will reset all LED values will reset  and the loop goes to counter == 0 and code runs again !
  else if(counter == 6 && !messagePrinted) {
    Serial.println("The data Has been reset and colors can be changed again ") ;
    Red_Val = 0 ; 
    Blue_Val = 0 ;
    Green_Val = 0 ;
    messagePrinted = false ;
    counter = 0 ; 
  }
}