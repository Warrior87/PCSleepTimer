#include <Keyboard.h>
byte GNDPin = 3;
byte VCCPin = 2;
byte dataPin = 4;
byte sleepSetFlag = 0;

void setup() {
  pinMode(GNDPin, OUTPUT);
  digitalWrite(GNDPin, LOW);
  pinMode(VCCPin, OUTPUT);
  digitalWrite(VCCPin, HIGH);
  pinMode(dataPin, INPUT_PULLUP);
  Keyboard.begin();
  delay(10000);
  Keyboard.press(KEY_F1);
  delay(100);
  Keyboard.releaseAll();
}

void loop() {
  if(!sleepSetFlag){
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
      sleepSetFlag = 1;
    }
  }
}
