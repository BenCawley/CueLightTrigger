#include "remoteFunctions.h"

void setup() {
    for (int i = 0; i < 6; i++) {
        pinMode(inPins[i], INPUT_PULLUP);
        if (i < 2)) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    digitalWrite(outPins[0], LOW);
    digitalWrite(outPins[1], HIGH);
}

void loop() {
    channelCheck(dipCheck);
}