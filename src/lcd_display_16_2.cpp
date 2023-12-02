#include "lcd_display_16_2.h"

LcdDisplay16_2::LcdDisplay16_2(): lcd(rs, en, d4, d5, d6, d7){
}

void LcdDisplay16_2::setup() {
    lcd.begin(16,2);
    show_text("Hello World!");
    analogWrite(v0, contrast_level);
}

void LcdDisplay16_2::increase_contrast() {
    if (contrast_level > contrast_max) {
        contrast_level = contrast_min;
    }
    contrast_level ++;
    analogWrite(v0, contrast_level);
    lcd.clear();
    lcd.print(contrast_level);
    delay(contrast_button_delay);
}

void LcdDisplay16_2::show_text(const String& text){
    if (text == print_text) {
        return;
    }
    print_text = text;
    show_text();
}

void LcdDisplay16_2::show_text() {
    int text_len = (int)print_text.length(), text_start = text_len > COLUMN_LEN ? text_len - COLUMN_LEN : 0;
    String text_to_print = print_text.substring(text_start, text_len);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text_to_print);
}

void LcdDisplay16_2::show_result(const String& text) {
    int text_len = (int)text.length();
    show_text();
    lcd.setCursor(COLUMN_LEN-text_len, ROW_LEN - 1);
    lcd.print(text);

}