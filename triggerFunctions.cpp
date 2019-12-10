#include "triggerFunctions.h"

const int outPins[5] = {2, 3, 13, 4, 5};
const int triggerPins[7] = {6, 7, 8, 9, 10, 11, 12};
int previousState = 0;

int relayRead() {
    for (int i = 0; i < 7; i++) {
        if (digitalRead(triggerPins[i]) == LOW) {
            return(i+1);
        }
    }
    return(0);
}

void channelCheck() {
    int currentState = relayRead();
    Serial.print("\nTrigger ");
    Serial.print(currentState);
    Serial.print("\n");
    if (currentState != previousState) {
        previousState = currentState;    
        switch (currentState) {
            case 0:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], HIGH);
                digitalWrite(outPins[2], HIGH);
                Serial.print("No Channel Triggered\n");
                break;
            case 1:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], HIGH);
                digitalWrite(outPins[2], HIGH);
                Serial.print("Channel 1 Triggered\n");
                break;
            case 2:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], LOW);
                digitalWrite(outPins[2], HIGH);
                Serial.print("Channel 2 Triggered\n");
                break;
            case 3:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], LOW);
                digitalWrite(outPins[2], HIGH);
                Serial.print("Channel 3 Triggered\n");
                break;
            case 4:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], HIGH);
                digitalWrite(outPins[2], LOW);
                Serial.print("Channel 4 Triggered\n");
                break;
            case 5:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], HIGH);
                digitalWrite(outPins[2], LOW);
                Serial.print("Channel 5 Triggered\n");
                break;
            case 6:
                digitalWrite(outPins[0], HIGH);
                digitalWrite(outPins[1], LOW);
                digitalWrite(outPins[2], LOW);
                Serial.print("Channel 6 Triggered\n");
                break;
            case 7:
                digitalWrite(outPins[0], LOW);
                digitalWrite(outPins[1], LOW);
                digitalWrite(outPins[2], LOW);
                Serial.print("Channel 7 Triggered\n");
                break;
        }
    }
}