#include "remoteFunctions.h"

const int inPins[7] = {2, 3, 9, 4, 5, 6, 7};
const int outPins[2] = {8, 10};

byte previousState = 0b000;

const byte pinMask[3] = {
    0b001, 0b010, 0b100
};

byte dipCheck() {
    byte dipChan = 0b000;
    for (int i = 0; i < 3; i++) {
        if (digitalRead(inPins[i + 3]) == LOW) {
            dipChan |= pinMask[i];
        }
    }
    Serial.print("\ndipCheck return: ");
    Serial.print(dipChan, BIN);
    Serial.print("\n");
    return (dipChan);
}

void channelCheck() {
    byte dipChan = dipCheck();
    byte pinState = 0b000;
    Serial.print("pinState reset check: ");
    Serial.print(pinState);
    Serial.print("\n");
    for (int i = 0; i < 3; i++) {
        if (digitalRead(inPins[i]) == HIGH) {
          continue;
        }
        else if (digitalRead(inPins[i] == LOW)) {
            pinState |= pinMask[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        Serial.print("Pin ");
        Serial.print(i);
        Serial.print(" level: ");
        Serial.print(digitalRead(inPins[i]));
        Serial.print("\n");
    }
    Serial.print("\nCurrent pinState: ");
    Serial.print(pinState, BIN);
    Serial.print("\n");
    if (pinState == dipChan) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], HIGH);
            digitalWrite(outPins[1], LOW);
            Serial.print("LED On\n");
        }
    }
    else if (pinState != dipChan) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], LOW);
            digitalWrite(outPins[1], HIGH);
            Serial.print("LED Off\n");
        }
    }
}