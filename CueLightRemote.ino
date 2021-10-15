#include "remoteFunctions.h"

void setup() { //Setup in / out pins
    for (int i = 0; i < 7; i++) {
        pinMode(inPins[i], INPUT_PULLUP);
        if (i < 2) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    digitalWrite(outPins[0], LOW); //Set LED and tally to default off
    digitalWrite(outPins[1], HIGH);
}

void loop() {
    channelCheck();
}