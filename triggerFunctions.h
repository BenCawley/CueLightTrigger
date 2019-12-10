#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int outPins[5];
extern const int triggerPins[7];
extern int previousState;

void setup();
void loop();

int relayRead();

void channelCheck();

#endif