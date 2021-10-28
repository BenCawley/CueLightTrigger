#include "triggerFunctions.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//Setup in and out pins
void setup() {
    pinMode(debugPin, INPUT_PULLUP);
    for (int i = 0; i < 6; i++) {
        pinMode(triggerPins[i], INPUT_PULLUP);
        if (i < 5) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(outPins[i], HIGH); //Default output pins to null state (no channel)
    }

    lcd.begin();
    lcd.backlight();
}

void loop() {
    channelCheck(debugCheck());
}