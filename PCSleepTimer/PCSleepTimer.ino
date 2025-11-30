#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  delay(10000);
  Keyboard.press(KEY_F1);
  delay(100);
  Keyboard.releaseAll();
}

void loop() {
}
