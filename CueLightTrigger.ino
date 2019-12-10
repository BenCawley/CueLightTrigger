#include "triggerFunctions.h"

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 7; i++) {
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
    Serial.print("Loop\n");
    channelCheck();
}