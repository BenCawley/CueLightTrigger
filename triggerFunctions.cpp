#include "triggerFunctions.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int outPins[7] = {2, 3, 13, 4, 5, 18, 19}; //2, 3 & 13 are output bus relays, 4 & 5 are the status LEDs, 18 & 19 are the I2C Bus
const int triggerPins[7] = {6, 7, 8, 9, 10, 11, 12}; //Tallyman output relays (arduino input)
int previousState = 0;
const int debugPin = 17;

//Check debug switch, change display backlight state
bool debugCheck() {
    if (digitalRead(debugPin) == LOW) {
        backlight();
        digitalWrite(outPins[4], LOW);
        digitalWrite(outPins[5], HIGH);
        return(true);
    }
    noBacklight();
    digitalWrite(outPins[4], HIGH);
    digitalWrite(outPins[5], LOW);
    return(false);
}

//Get state of input relays
int relayRead() {
    for (int i = 0; i < 7; i++) {
        if (digitalRead(triggerPins[i]) == LOW) {
            return(i+1);
        }
    }
    return(0);
}

//Depending on which input relay is active, adjust 3 bit output relays with a switch case
void channelCheck() {
    int currentState = relayRead();
    bool debugState = debugCheck();
    if (currentState != previousState) {
        previousState = currentState;
        switch(debugState) {
            case true:
                switch (currentState) {
                    case 0:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], HIGH);
                        clear();
                        lcd.print(1);
                        break;
                    case 1:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], HIGH);
                        clear();
                        lcd.print(2);
                        break;
                    case 2:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], HIGH);
                        clear();
                        lcd.print(3);
                        break;
                    case 3:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], HIGH);
                        clear();
                        lcd.print(4);
                        break;
                    case 4:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], LOW);
                        clear();
                        lcd.print(5);
                        break;
                    case 5:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], LOW);
                        clear();
                        lcd.print(6);
                        break;
                    case 6:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], LOW);
                        clear();
                        lcd.print(7);
                        break;
                    case 7:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], LOW);
                        clear();
                        lcd.print(8);
                        break;
                }
            case false:
                switch (currentState) {
                    case 0:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], HIGH);
                        break;
                    case 1:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], HIGH);
                        break;
                    case 2:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], HIGH);
                        break;
                    case 3:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], HIGH);
                        break;
                    case 4:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], LOW);
                        break;
                    case 5:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], HIGH);
                        digitalWrite(outPins[2], LOW);
                        break;
                    case 6:
                        digitalWrite(outPins[0], HIGH);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], LOW);
                        break;
                    case 7:
                        digitalWrite(outPins[0], LOW);
                        digitalWrite(outPins[1], LOW);
                        digitalWrite(outPins[2], LOW);
                        break;
                }
        }
    }
}