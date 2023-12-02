
#ifndef ARDUINOMATHCALCULATOR_KEYBOARD_4_4_H
#define ARDUINOMATHCALCULATOR_KEYBOARD_4_4_H

#include <Arduino.h>

class Keyboard_4_4 {
    public:
        Keyboard_4_4();
        char get_key();
        int get_key_number() const;
        const char CHANGE_MODE = 'C', CLEAR_SCREEN = 'A', EQUALS = '=', COMMA = '.', PLUS = '+', MINUS = '-',
                   MULTIPLY = '*', DIVIDE = '|';
        int get_current_mode() const { return current_mode; }
    private:
        // C - change mode
        const int KEY_INPUT[16] = {562, 744, 398, 797, 572, 748, 416, 800, 594, 756,
                             455, 805, 668, 787, 578, 826};
        const char KEY_OUTPUT_A[16] = {'1', '2', '3', CLEAR_SCREEN, '4', '5', '6', PLUS,
                                 '7', '8', '9', MINUS, COMMA, '0', CHANGE_MODE, EQUALS};
        const char KEY_OUTPUT_B[16] = {'1', '2', '3', CLEAR_SCREEN, '4', '5', '6', MULTIPLY,
                                       '7', '8', '9', DIVIDE, COMMA, '0', CHANGE_MODE, EQUALS};
        const int PIN = A2, DEFAULT_INPUT = 1023, MODEL_LEN = 2;
        int last_pressed = DEFAULT_INPUT, current_mode = 0;
        bool already_pressed = false;
        void change_mode();
        char get_output(int key_number);
        char get_output_by_mode(int key_number);
};

typedef Keyboard_4_4 Keyboard;

#endif