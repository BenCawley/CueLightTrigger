#include "triggerFunctions.h"

void setup() {
    for (int i = 0; i < 6; i++) {
        pinMode(triggerPins[i], INPUT_PULLUP);
        if (i < 5) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(outPins[i], HIGH);
    }
}

void loop() {
    channelCheck();
}