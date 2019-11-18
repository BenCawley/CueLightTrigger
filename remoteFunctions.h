#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int inPins[4];
extern const int outPins[2];
extern byte pinState;

extern byte previousState;

extern const byte inChannels[4];

void channelCheck();

int dipCheck();

void setup();
void loop();

#endif