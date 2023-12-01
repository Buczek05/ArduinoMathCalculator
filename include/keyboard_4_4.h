
#ifndef ARDUINOMATHCALCULATOR_KEYBOARD_4_4_H
#define ARDUINOMATHCALCULATOR_KEYBOARD_4_4_H

#include <Arduino.h>

class Keyboard_4_4 {
    public:
        Keyboard_4_4();
        char get_key();

    private:
        int key_input[16] = {562, 744, 397, 797, 572, 748, 416, 800, 594, 756,
                             454, 805, 668, 787, 577, 826};
        char key_output[16] = {'1', '2', '3', 'A', '4', '5', '6', '+',
                               '7', '8', '9', '-', '*', '0', '/', '='};
        const int pin = A2, default_input = 1023;
        int last_pressed = default_input;
        bool already_pressed = false;
};

typedef Keyboard_4_4 Keyboard;

#endif