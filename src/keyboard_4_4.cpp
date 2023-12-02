#include "keyboard_4_4.h"

Keyboard_4_4::Keyboard_4_4() {
    pinMode(PIN, INPUT);
}

char Keyboard_4_4::get_key() {
    int key = analogRead(PIN);
    if (key == DEFAULT_INPUT || key == last_pressed) {
        last_pressed = key;
        return ' ';
    }
    for (int i = 0; i < 16; i++) {
        if (KEY_INPUT[i] == key) {
            last_pressed = key;
            return get_output(i);
        }
    }
    return ' ';
}

int Keyboard_4_4::get_key_number() const{
    return analogRead(PIN);
}

void Keyboard_4_4::change_mode() {
    current_mode = (current_mode + 1) % MODEL_LEN;
}

char Keyboard_4_4::get_output(int key_number) {
    char key_output = get_output_by_mode(key_number);
    if (key_output == CHANGE_MODE) {
        change_mode();
        return key_output;
    }
    return key_output;
}

char Keyboard_4_4::get_output_by_mode(int key_number) {
    if (current_mode == 0) {
        return KEY_OUTPUT_A[key_number];
    }
    if (current_mode == 1) {
        return KEY_OUTPUT_B[key_number];
    }
    return ' ';
}