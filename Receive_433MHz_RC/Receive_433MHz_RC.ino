#include <RCSwitch.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
RCSwitch mySwitch = RCSwitch();
int lcdColumns = 16;
int lcdRows = 2;

//You should check Slave address before set address, Default address is 0x27 or 0x3f 
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);   //Connect Pin SDA, SCL from LCD Display to Pin 21, 22 ON ESP32

#define RXD2 27     //Connect Pin Data to Pin 27 on ESP32

void setup() {
  Serial.begin(115200);
  Serial.print("Ready to receive.");  
  mySwitch.enableReceive(RXD2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Received");
  lcd.setCursor(0,1);
  lcd.print("B");
  lcd.setCursor(1,1);
}

void loop() {    
  if (mySwitch.available()) {
    char data = char(mySwitch.getReceivedValue());
    lcd.print(data);
    mySwitch.resetAvailable();
    if(data == '#'){  //if you press # on keypad it will make LCD Clear and set point for receive new student ID
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
