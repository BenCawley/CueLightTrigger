#include "triggerFunctions.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//Setup in and out pins
void setup() {
    pinMode(debugPin, INPUT_PULLUP);
    for (int i = 0; i < 7; i++) {
        pinMode(triggerPins[i], INPUT_PULLUP);
        pinMode(outPins[i], OUTPUT);
    }
    for (int i = 0; i < 4; i++) {
        digitalWrite(outPins[i], HIGH); //Default output relay pins to null state (no channel) and turns on the normal operation LED (4)
    }
    LiquidCrystal_I2C lcd(0x26, 16, 2);
    lcd.begin();
    lcd.backlight();
}

void loop() {
    channelCheck();
}
