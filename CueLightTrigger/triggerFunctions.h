#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int outPins[7];
extern const int triggerPins[7];
extern int previousState;
extern const int debugPin;

void setup();
void loop();

bool debugCheck();
int relayRead();
void channelCheck();

#endif
