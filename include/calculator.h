#ifndef ARDUINOMATHCALCULATOR_CALCULATOR_H
#define ARDUINOMATHCALCULATOR_CALCULATOR_H

#include <Arduino.h>
#include "keyboard_4_4.h"

#define NUMBERS_LEN 11
#define MAX_TABLE_INDEX 100

class Calculator {
    public:
        Calculator() = default;
        String calculate(const String& text);
    private:
        const char NUMBERS[NUMBERS_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int table_index = 0;
        bool check_equal(String text);
        String *split_equal(const String& text);
        void add_char_to_table(String *split_text, char letter);
        static bool check_split_text(String *split_text);
        bool is_number(char letter);
        static bool is_comma(char letter);
        static int count_comma(const String& text);
        static String calculate_table(String *split_text);
        static void calculate_table_first_priority(String *split_text);
        static void calculate_table_last_priority(String *split_text);
        static void move_2_left(String *split_text, int start_index, int end_index);
        static int count_table(String *split_text);
};


#endif