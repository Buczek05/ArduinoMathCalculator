#include <Arduino.h>
#include "lcd_display_16_2.h"
#include "keyboard_4_4.h"
#include "calculator.h"

int KeyIn = 0;
Display display;
Keyboard keyboard;
Calculator calculator;

void setup() {
    display.setup();
}

char key;
String text;
void loop() {
    key = keyboard.get_key();
    if (key == keyboard.CLEAR_SCREEN) {
        text = "";
        display.show_text(text);
    }
    else if (key == keyboard.EQUALS) {
        display.show_result(calculator.calculate(text));
    }
    else if (key == keyboard.CHANGE_MODE) {
        display.show_result(String(keyboard.get_current_mode()));
    }
    else if (key != ' ') {
        text += key;
        display.show_text(text);
    }
    delay(100);
}
