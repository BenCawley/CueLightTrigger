#include "triggerFunctions.h"

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(outPins[i], OUTPUT);
        pinMode(triggerPins[i], INPUT_PULLUP);
    }
}

void loop() {
    channelCheck();
}