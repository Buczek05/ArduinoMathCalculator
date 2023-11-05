#include <Arduino.h>
#include <displays/lcd_display_16_2.h>

Display display;

void setup() {
}

void loop() {
    display.show("Witaj świecie!");
    delay(2000);
}
