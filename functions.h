#ifndef _HF_
#define _HF_
#include "Arduino.h"

extern const int relayPins[4];
extern const int triggerPins[4];
extern bool triggerState[4];

void setup();
void loop();

#endif