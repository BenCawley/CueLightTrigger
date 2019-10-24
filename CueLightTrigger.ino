#include "functions.h"

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(relayPins[i], OUTPUT);
        pinMode(triggerPins[i], INPUT_PULLUP);
    }
}

void loop() {
    for (int i = 0; i < 4; i++) {
        triggerState[i] = digitalRead(triggerPins[i]);

        if (triggerState[i] == LOW) {
            digitalWrite(relayPins[i], HIGH);
        }
        else if (triggerState[i] == HIGH) {
            digitalWrite(relayPins[i], LOW);
        }
    }
}
