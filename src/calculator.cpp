#include "calculator.h"


String Calculator::calculate(const String &text) {
    String *split_text = split(text);
    String first_number = split_text[0], second_number = split_text[2], operator_sign = split_text[1];
    if (operator_sign == "+") {
        return String(first_number.toFloat() + second_number.toFloat());
    }
    if (operator_sign == "-") {
        return String(first_number.toFloat() - second_number.toFloat());
    }
    if (operator_sign == "*") {
        return String(first_number.toFloat() * second_number.toFloat());
    }
    if (operator_sign == "/") {
        return String(first_number.toFloat() / second_number.toFloat());
    }
    return text;
}

String *Calculator::split(const String &text) {
    String *split_text = new String[3];
    table_index = 0;
    int text_len = (int)text.length();
    for (int letter_index = 0; letter_index < text_len; letter_index++) {
        add_char_to_table(split_text, text[letter_index]);
    }
    return split_text;
}

void Calculator::add_char_to_table(String *split_text, char letter) {
    for (int i = 0; i < NUMBERS_LEN; i++) {
        if (letter == NUMBERS[i]) {
            split_text[table_index] += letter;
            return;
        }
    }
    table_index++;
    split_text[table_index++] += letter;
}