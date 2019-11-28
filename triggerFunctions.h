#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int outPins[4];
extern const int triggerPins[4];
extern int previousState;

void setup();
void loop();

int relayRead();

void channelCheck();

#endif