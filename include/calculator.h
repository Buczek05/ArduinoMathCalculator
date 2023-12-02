#ifndef ARDUINOMATHCALCULATOR_CALCULATOR_H
#define ARDUINOMATHCALCULATOR_CALCULATOR_H

#include <Arduino.h>

#define NUMBERS_LEN 11

class Calculator {
    public:
        Calculator() {};
        String calculate(const String& text);

    private:
        String *split(const String& text);
        int table_index;
        void add_char_to_table(String *split_text, char letter);
        const char NUMBERS[NUMBERS_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
};


#endif