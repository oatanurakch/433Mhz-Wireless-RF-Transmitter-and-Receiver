#include <RCSwitch.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};  //ESP32 Connect Pin keypad 8, 7, 6, 5
byte colPins[COLS] = {5, 4, 3, 2};    //ESP32 Connect Pin keypad 4, 3, 2, 1
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

RCSwitch mySwitch = RCSwitch();
void setup() {
  mySwitch.enableTransmit(12); // Using Pin #D12
  Serial.begin(115200);
}
void loop() {
  char key = keypad.getKey();
    if(key != NO_KEY){
      mySwitch.send(key, 24);
      Serial.println(key);
  }
  key = NO_KEY;
}
