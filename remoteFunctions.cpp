#include "remoteFunctions.h"

const int inPins[6] = {2, 3, 4, 5, 6, 7};
const int outPins[2] = {8, 9};

byte previousState = 0b00;

const byte inChannels[4] = {
    0b00, 0b01, 0b10, 0b11
};

const byte pinMask[3] = {
    0b01, 0b10, 0b00
};

int dipCheck() {
    for (int i = 2; i < 6; i++) {
        if (digitalRead(inPins[i]) == LOW) {
            return (i - 2);
        }
    }
}

void channelCheck(int dipChan) {
    byte pinState = 0b00;
    for (int i = 0; i < 2; i++) {
        if (digitalRead(inPins[i] == LOW)) {
            pinState |= pinMask[i];
        }
    }
    if (pinState == inChannels[dipChan]) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], HIGH);
            digitalWrite(outPins[1], LOW);
        }
    }
    else if (pinState != inChannels[dipChan]) {
        digitalWrite(outPins[0], LOW);
        digitalWrite(outPins[1], HIGH);
    }
}