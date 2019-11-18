#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int outPins[4];
extern const int triggerPins[4];
extern bool triggerState[4];

extern const byte outChannels[4]
extern int previousState;

void setup();
void loop();

void channelCheck();

#endif