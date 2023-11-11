#ifndef ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H
#define ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdDisplay16_2 {
    public:
        LcdDisplay16_2();
        void setup();
        void contrast_button();
        void show_text(String text);
        void show_text();

    private:
        const int rs = 12, en = 10, d4 = 4, d5 = 5, d6 = 6, d7 = 7, v0 = 3;
        const int contrast_button_pin = 11;
        const int contrast_button_delay = 50, contrast_min = 0, contrast_max = 100;
        const unsigned long contrast_button_return_text_time = 1000 * 3;
        unsigned long contrast_button_click_time = 0;
        int contrast_level = 30;
        String print_text;
        LiquidCrystal lcd;
        void increase_contrast();
};

typedef LcdDisplay16_2 Display;

#endif