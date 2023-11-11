#include "lcd_display_16_2.h"

LcdDisplay16_2::LcdDisplay16_2(): lcd(rs, en, d4, d5, d6, d7){
}

void LcdDisplay16_2::setup() {
    lcd.begin(16,2);
    show_text("Hello World!");
    analogWrite(v0, contrast_level);
    pinMode(contrast_button_pin, INPUT_PULLUP);
}

void LcdDisplay16_2::contrast_button(){
    unsigned long time = millis();
    if (time - contrast_button_click_time >= contrast_button_return_text_time
    && contrast_button_click_time != 0) {
        show_text();
        contrast_button_click_time = 0;
    }
    if (digitalRead(contrast_button_pin) == LOW) {
        contrast_button_click_time = time;
        increase_contrast();
    }
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

void LcdDisplay16_2::show_text(String text){
    lcd.clear();
    lcd.print(text);
    print_text = text;
}

void LcdDisplay16_2::show_text() {
    lcd.clear();
    lcd.print(print_text);
}