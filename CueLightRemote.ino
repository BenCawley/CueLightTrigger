#include "remoteFunctions.h"

void setup() {
    Serial.begin(9600);
    Serial.print("Remote Startup\n");
    for (int i = 0; i < 7; i++) {
        pinMode(inPins[i], INPUT_PULLUP);
        if (i < 2) {
            pinMode(outPins[i], OUTPUT);
        }
    }
    digitalWrite(outPins[0], LOW);
    digitalWrite(outPins[1], HIGH);
}

void loop() {
    Serial.print("Loop ");
    Serial.print("\n");

    channelCheck();
}