#include "calculator.h"


String Calculator::calculate(const String &text) {
    if (!check_equal(text)) {
        return "ERROR";
    }
    String *split_text = split_equal(text);
    if (!check_split_text(split_text)) {
        return "ERROR";
    }
    return calculate_table(split_text);
}

bool Calculator::check_equal(String text) {
    if (!is_number(text[0]) || !is_number(text[text.length() - 1])) {
        return false;
    }
    for (int i = 0; i < text.length() - 1; i++) {
        if ((!is_number(text[i]) && !is_comma(text[i])) &&
            (!is_number(text[i + 1]) && !is_comma(text[i + 1]))) {
            return false;
        }
    }
    return true;
}

String *Calculator::split_equal(const String &text) {
    int text_len = (int)text.length();
    auto *split_text = new String[MAX_TABLE_INDEX];
    table_index = 0;
    for (int letter_index = 0; letter_index < text_len; letter_index++) {
        add_char_to_table(split_text, text[letter_index]);
    }
    return split_text;
}

void Calculator::add_char_to_table(String *split_text, char letter) {
    if (is_number(letter) || is_comma(letter)) {
        split_text[table_index] += letter;
        return;
    }
    table_index++;
    split_text[table_index++] += letter;
}

bool Calculator::check_split_text(String *split_text) {
    for (int i = 0; i < MAX_TABLE_INDEX; i++) {
        if (count_comma(split_text[i]) > 1) {
            return false;
        }
    }
    return true;
}

bool Calculator::is_number(char letter) {
    for (char i : NUMBERS) {
        if (letter == i) {
            return true;
        }
    }
    return false;
}

bool Calculator::is_comma(char letter) {
    return letter == ',';
}

int Calculator::count_comma(const String& text) {
    int comma_count = 0;
    for (char i : text) {
        if (is_comma(i)) {
            comma_count++;
        }
    }
    return comma_count;
}

String Calculator::calculate_table(String *split_text) {
    calculate_table_first_priority(split_text);
    calculate_table_last_priority(split_text);
    return split_text[0];
}

void Calculator::calculate_table_first_priority(String *split_text) {
    Keyboard keyboard;
    int table_len, i;
    table_len = count_table(split_text);
    for (i = 1; i < table_len; i++) {
        if (split_text[i] == String(keyboard.MULTIPLY)) {
            split_text[i - 1] = String(split_text[i - 1].toFloat() * split_text[i + 1].toFloat());
            move_2_left(split_text, i, table_len);
            calculate_table_first_priority(split_text);
        } else if (split_text[i] == String(keyboard.DIVIDE)) {
            split_text[i - 1] = String(split_text[i - 1].toFloat() / split_text[i + 1].toFloat());
            move_2_left(split_text, i, table_len);
            calculate_table_first_priority(split_text);
        }
    }
}

void Calculator::calculate_table_last_priority(String *split_text) {
    Keyboard keyboard;
    int table_len, i;
    table_len = count_table(split_text);
    for (i = 1; i < table_len; i++) {
        if (split_text[i] == String(keyboard.PLUS)) {
            split_text[i - 1] = String(split_text[i - 1].toFloat() + split_text[i + 1].toFloat());
            move_2_left(split_text, i, table_len);
            calculate_table_last_priority(split_text);
        } else if (split_text[i] == String(keyboard.MINUS)) {
            split_text[i - 1] = String(split_text[i - 1].toFloat() - split_text[i + 1].toFloat());
            move_2_left(split_text, i, table_len);
            calculate_table_last_priority(split_text);
        }
    }
}

void Calculator::move_2_left(String *split_text, int start_index, int end_index) {
    for (int i = start_index; i < end_index - 2; i++) {
        split_text[i] = split_text[i + 2];
    }
    split_text[end_index - 2] = "";
    split_text[end_index - 1] = "";
}

int Calculator::count_table(String *split_text) {
    for (int i = 0; i < MAX_TABLE_INDEX; i++) {
        if (split_text[i] == "") {
            return i;
        }
    }
    return MAX_TABLE_INDEX;
}