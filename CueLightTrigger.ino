#include "triggerFunctions.h"

//Setup in and out pins
void setup() {
    for (int i = 0; i < 6; i++) {
        pinMode(triggerPins[i], INPUT_PULLUP);
        if (i < 5) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(outPins[i], HIGH); //Default output pins to null state (no channel)
    }
}

void loop() {
    channelCheck();
}