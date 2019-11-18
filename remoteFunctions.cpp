#include "remoteFunctions.h"

const int inPins[6] = {2, 3, 4, 5, 6, 7};
const int outPins[2] = {8, 9};

byte previousState = NULL;

byte pinState = {00};

const byte inChannels[4] = {
    {00}, {01}, {10}, {11}
};

int dipCheck() {
    for (int i = 0; i < 4; i++) {
        if (digitalRead(inPins[i]) == LOW) {
            return i;
        }
    }
}

void channelCheck(int dipChan) {
    for (int i = 0; i < 2; i++) {
        pinState[i] = digitalRead(inPins[i]);
    }
    if (pinState == inChannels[dipChan]) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], HIGH);
            digitalWrite(outPins[1], LOW);
        }
        else if (pinState == previousState) {
            break;
        }
    }
    else if (pinState != inChannels[dipChan]) {
        digitalWrite(outPins[0], LOW);
        digitalWrite(outPins[1], HIGH);
    }
}