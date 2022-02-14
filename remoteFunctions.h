#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int inPins[7];
extern const int outPins[2];

extern byte previousState;

extern const byte pinMask[3];

void channelCheck();

byte dipCheck();

void setup();
void loop();

#endif