//A short script running on another arduino to soak test the CueLightTrigger box inputs 
#include "Arduino.h"

int outPins[7] = {2, 3, 4, 5, 6, 7, 8};
int randPin = A0; //Floating analogue input to generate random number
int switchPin = 9; //Pin for changing modes
int led = 10;

void setup() { //Setting up inputs/outputs
    Serial.begin(9600); 
    for (int i = 0; i < 7; i++) {
        pinMode(outPins[i], OUTPUT);
        digitalWrite(outPins[i], HIGH);
    }
    pinMode(randPin, INPUT);
    pinMode(switchPin, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);

    int mode = 0; //Keeps track of testing mode
}
//Turn on a random channel at random interval between 2 and 8 seconds
void randomTest() {
    randomSeed(analogRead(randPin));
    int randNum = random(7);
    int randTime = random(2000, 8000);

    digitalWrite(outPins[randNum], LOW);
    Serial.print("\nChannel: ");
    Serial.print(randNum);
    Serial.print("\nDelay: ");
    Serial.print(randTime);
    Serial.print("\n");
    delay(randTime);
    digitalWrite(outPins[randNum], HIGH);
}

//Just test each channel in order
void linearTest() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(outPins[i], LOW);
        delay(1000);
        digitalWrite(outPins[i], HIGH);
    }
}

void rapidLinearTest() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(outPins[i], LOW);
        delay(200);
        digitalWrite(outPins[i], HIGH);
    }   
}

void blink(int number) {
    for (int i = 0; i < number+1; i++) {
        digitalWrite(led, LOW);
        delay(250);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(250);
        digitalWrite(led, HIGH);
    }
}

void loop() { 
    while(digitalRead(switchPin) == HIGH) {
        switch (mode) {
            case 0:
                linearTest();
                break;
            case 1:
                rapidLinearTest();
                break;
            case 2:
                randomTest();
        }
    }
    mode++;
    blink(mode);
}