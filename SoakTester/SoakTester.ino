//A short script running on another arduino to soak test the CueLightTrigger box inputs 
#include "Arduino.h"

const int outPins[7] = {3, 4, 5, 6, 7, 8, 9};
const int randPin = A0; //Floating analogue input to generate random number
const int switchPin = 2; //Interrupt pin for changing modes
const int led = 10;
volatile int mode = 0; //Keeps track of testing mode
int flashCount = 0; //Keeps track of how many times the led has flashed per cycle
unsigned long previousMillis = 0; //stores the last time the led was updated
const long shortInt = 250; 
const long longInt = 2000; //Timings for the led flashes

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
    digitalWrite(led, LOW);
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

//Check whether the led has flashed and trigger it to flash again based on time
void flashCheck() {
    if (flashCount = 0) {
        flash(longInt);
    }
    else {
        flash(shortInt;)
    }
}

void flash(int interval) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        //Save the last time you blinked the LED
        previousMillis = currentMillis;

        //If the LED is off turn it on and vice-versa:
        digitalWrite(led, !digitalRead(led));
        //Increment the count for number of flashes, if its more than the mode, reset count
        flashCount++;
        if (flashCount > mode) {
            flashCount = 0;
        }
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
    flashCheck();
}
