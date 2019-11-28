#include "triggerFunctions.h"

const int outPins[4] = {2, 3, 4, 5};
const int triggerPins[4] = {6, 7, 8, 9};
int previousState = 0;

int relayRead() {
    for (int i = 0; i < 4; i++) {
        if (digitalRead(triggerPins[i]) == LOW) {
            currentState = outChannels[i];
            Serial.print("\nTrigger ");
            Serial.print(i);
            return(i);
        }
    }
}

void channelCheck() {
    int currentState = relayRead();
    if (currentState != previousState) {
        previousState = currentState;    
        switch (currentState) {
            case 0:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], HIGH);
                Serial.print("Channel 1\n");
                break;
            case 1:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], HIGH);
                Serial.print("Channel 2\n");
                break;
            case 2:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], LOW);
                Serial.print("Channel 3\n");
                break;
            case 3:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], LOW);
                Serial.print("Channel 4\n");
                break;
        }
    }
}