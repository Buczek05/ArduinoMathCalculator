#include "lcd_display_16_2.h"

LcdDisplay16_2::LcdDisplay16_2()
        : lcd(rs, en, d4, d3, d2, d1) {
    lcd.begin(16, 2);
}

void LcdDisplay16_2::show(const String &text) {
    lcd.clear();
    lcd.print(text);
}
