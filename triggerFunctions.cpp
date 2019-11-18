#include "triggerFunctions.h"

const int outPins[4] = {2, 3, 4, 5};
const int triggerPins[4] = {6, 7, 8, 9};
bool triggerState[4] = {false, false, false, false};

int previousState = NULL;

const byte outChannels[4] = {
    {00}, {01}, {10}, {11}
};

void channelCheck() {
    for (int i = 0; i < 4; i++) {
        triggerState[i] = digitalRead(triggerPins[i]);
        if (triggerState[i] == LOW) {
            if (i == previousState) {
                continue;
            }
            else if (i != previousState) {
                previousState = i;
                for (int j = 1; j >= 0; j--) {
                    digitalWrite(outPins[j], outChannels[i][j]);
                }
            }
        }
        else if (triggerState[i] == HIGH) {
            continue;
        }
    }
}