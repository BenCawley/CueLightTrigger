//A short script running on another arduino to soak test the CueLightTrigger box inputs 

int outPins[4] = {2, 3, 4, 5};
int inPins = A0;

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 4; i++) {
        pinMode(outPins[i], OUTPUT);
        digitalWrite(outPins[i], HIGH);
    }
    pinMode(inPins, INPUT);
}

void loop() {
    randomSeed(analogRead(inPins));
    int randNum = random(5);
    int randTime = random(100, 5000);

    digitalWrite(outPins[randNum], LOW);
    Serial.print("\nChannel: ");
    Serial.print(randNum);
    Serial.print("\nDelay: ");
    Serial.print(randTime);
    Serial.print("\n");
    delay(randTime);
    digitalWrite(outPins[randNum], HIGH);
}