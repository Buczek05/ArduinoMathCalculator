#ifndef ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H
#define ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdDisplay16_2 {
    public:
        LcdDisplay16_2();
        void setup();
        void show_text(const String& text);
        void show_text();
        void show_result(const String& text);

    private:
        const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7, v0 = 3, COLUMN_LEN = 16, ROW_LEN = 2;
        const int contrast_button_delay = 50, contrast_min = 0, contrast_max = 100;
        const unsigned long contrast_button_return_text_time = 1000 * 3;
        unsigned long contrast_button_click_time = 0;
        int contrast_level = 20;
        String print_text;
        LiquidCrystal lcd;
        void increase_contrast();
};

typedef LcdDisplay16_2 Display;

#endif