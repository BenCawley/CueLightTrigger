#include "remoteFunctions.h"

// 2, 3 & 9 are inputs for the controller's 3 relays, 4, 5, 6 & 7 are the channel select dip switches on the remote body (channels 1-4)
const int inPins[7] = {2, 3, 9, 4, 5, 6, 7};
const int outPins[2] = {8, 10}; //8 = LED, 10 = forward tally trigger

byte previousState = 0b000; //This is the off state, when non of the tallys are active

const byte pinMask[3] = { //Mask to help set channel bits
    0b001, 0b010, 0b100
};

//Read dipswitch pins and set dipChan byte accordingly to establish channel
byte dipCheck() {
    byte dipChan = 0b000;
    for (int i = 0; i < 3; i++) {
        if (digitalRead(inPins[i + 3]) == LOW) {
            dipChan |= pinMask[i];
        }
    }
    return (dipChan);
}

//Read incomming relays from trigger unit and compare them to dipChan byte to see if the LED & forward tally should be turned on
void channelCheck() {
    byte dipChan = dipCheck();
    byte pinState = 0b000;
    for (int i = 0; i < 3; i++) {
        if (digitalRead(inPins[i]) == HIGH) {
          continue;
        }
        else if (digitalRead(inPins[i] == LOW)) {
            pinState |= pinMask[i];
        }
    }
    if (pinState == dipChan) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], HIGH);
            digitalWrite(outPins[1], LOW);
        }
    }
    else if (pinState != dipChan) {
        if (pinState != previousState) {
            previousState = pinState;
            digitalWrite(outPins[0], LOW);
            digitalWrite(outPins[1], HIGH);
        }
    }
}