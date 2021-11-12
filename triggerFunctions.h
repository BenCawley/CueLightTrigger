#ifndef _HF_
#define _HF_
#include "Arduino.h"

LiquidCrystal_I2C lcd(0x26, 16, 2);

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