#include <Keyboard.h>
byte GNDPin = 3;
byte VCCPin = 2;
byte dataPin = 4;

void setup() {
  pinMode(GNDPin, OUTPUT);
  digitalWrite(GNDPin, LOW);
  pinMode(VCCPin, OUTPUT);
  digitalWrite(VCCPin, HIGH);
  pinMode(dataPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if(digitalRead(dataPin) == 0){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.print("shutdown -s -t 1800");
    delay(1000);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
  }
  
}
