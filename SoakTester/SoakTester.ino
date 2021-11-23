//A short script running on another arduino to soak test the CueLightTrigger box inputs 
#include "Arduino.h"

const int outPins[7] = {3, 4, 5, 6, 7, 8, 9};
const int randPin = A0; //Floating analogue input to generate random number
const int switchPin = 2; //Interrupt pin for changing modes
const int led = 10;
volatile int mode = 0; //Keeps track of testing mode

void setup() { //Setting up inputs/outputs
    Serial.begin(9600); 
    for (int i = 0; i < 7; i++) {
        pinMode(outPins[i], OUTPUT);
        digitalWrite(outPins[i], HIGH);
    }
    pinMode(switchPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(switchPin), modeSet, LOW); //Sets up interrupt function

    pinMode(randPin, INPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    randomSeed(analogRead(randPin));
}

//Turn on a random channel at random interval between 2 and 8 seconds
void randomTest() {
    int randNum = random(0, 7);
    int randTime = random(1500, 8000);

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
        Serial.print(i);
        Serial.print("\n");
        delay(1000);
        digitalWrite(outPins[i], HIGH);
    }
}

//Gotta go fast >>>
void rapidLinearTest() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(outPins[i], LOW);
        Serial.print(i);
        Serial.print("\n");
        delay(200);
        digitalWrite(outPins[i], HIGH);
    }   
}

//Short led blink function to display current mode
void flash(int number) {
    for (int i = 0; i < number+1; i++) {
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
    }
}

//Interrupt Service Routine to change modes
void modeSet() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 200ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 200) {
        mode++;
        if (mode > 2) {
            mode = 0;
        }
        flash(mode);
        Serial.print("Mode ");
        Serial.print(mode);
        Serial.print("\n");
    }
    last_interrupt_time = interrupt_time;
}

void loop() { 
    switch (mode) {
        case 0:
            linearTest();
            break;
        case 1:
            rapidLinearTest();
            break;
        case 2:
            randomTest();
            break;
    }
}
