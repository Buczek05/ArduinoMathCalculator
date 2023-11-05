#ifndef ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H
#define ARDUINOMATHCALCULATOR_LCD_DISPLAY_16_2_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdDisplay16_2 {
private:
    const int rs = 6;
    const int en = 5;
    const int d4 = 4;
    const int d3 = 3;
    const int d2 = 2;
    const int d1 = 1;
    LiquidCrystal lcd;

public:
    LcdDisplay16_2();
    void show(const String &text);
};

typedef LcdDisplay16_2 Display;

#endif