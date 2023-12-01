#include "keyboard_4_4.h"

Keyboard_4_4::Keyboard_4_4() {
    pinMode(pin, INPUT);
}

char Keyboard_4_4::get_key() {
    int key = analogRead(pin);
    if (key == default_input || key == last_pressed) {
        last_pressed = key;
        return ' ';
    }
    for (int i = 0; i < 16; i++) {
        if (key_input[i] == key) {
            last_pressed = key;
            return key_output[i];
        }
    }
    return ' ';
}