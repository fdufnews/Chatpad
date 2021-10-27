#include <Chatpad.h>

Chatpad pad;

void print_keys(Chatpad &pad, Chatpad::keycode_t code,
    Chatpad::eventtype_t type) {
  if (type == Chatpad::Down) {
    char a = pad.toAscii(code);
    if (a != 0) Serial.print(a);
  }
}

void setup() {
  Serial.begin(115200);
  pad.init(Serial1, print_keys);
}

void loop() {
  pad.poll();
}
