#include <RCSwitch.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
RCSwitch mySwitch = RCSwitch();
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

#define RXD2 0  //Connect D2 On Arduino Uno R3 to Pin Data on Module

void setup() {
  Serial.begin(115200);
  Serial.print("Ready to receive.");  
  mySwitch.enableReceive(RXD2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Student ID: ");
  lcd.setCursor(0,1);
  lcd.print("B");
  lcd.setCursor(1,1);
}

void loop() {    
  if (mySwitch.available()) {
    char data = char(mySwitch.getReceivedValue());
    lcd.print(data);
    mySwitch.resetAvailable();
    if(data == '#'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Received");
      lcd.setCursor(0,1);
      lcd.print("B");
      lcd.setCursor(1,1);
    }
  }
  delay(1000);
}
