#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int inPins[6];
extern const int outPins[2];

extern byte previousState;

extern const byte inChannels[4];

extern const byte pinMask[3];

void channelCheck(int dipChan);

int dipCheck();

void setup();
void loop();

#endif