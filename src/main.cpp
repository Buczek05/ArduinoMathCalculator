#include <Arduino.h>
#include "lcd_display_16_2.h"
#include "keyboard_4_4.h"

int KeyIn = 0;
Display display;
Keyboard keyboard;

void setup() {
    display.setup();
}

char key;
String text;
void loop() {
    key = keyboard.get_key();
    if (key != ' ') {
        text += key;
        display.show_text(text);
    }
    delay(100);
}
