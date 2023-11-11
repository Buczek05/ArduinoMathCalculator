#include <Arduino.h>
#include "lcd_display_16_2.h"


Display display;
void setup() {
    display.setup();
}


void loop() {
    display.contrast_button();
}
