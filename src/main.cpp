#include <Arduino.h>

const int RED_GPIO = 4;
const int YELLOW_GPIO = 5;
const int GREEN_GPIO = 6;

const unsigned long RED_INTERVAL = 200;
const unsigned long YELLOW_INTERVAL = 500;
const unsigned long GREEN_INTERVAL = 1000;

unsigned long redTimer = 0;
unsigned long yellowTimer = 0;
unsigned long greenTimer = 0;

void setup() {
    Serial.begin(115200);

    pinMode(RED_GPIO, OUTPUT);
    pinMode(YELLOW_GPIO, OUTPUT);
    pinMode(GREEN_GPIO, OUTPUT);

    digitalWrite(RED_GPIO, LOW);
    digitalWrite(YELLOW_GPIO, LOW);
    digitalWrite(GREEN_GPIO, LOW);
}

void loop() {
    unsigned long now = millis();

    // RED
    if (now - redTimer >= RED_INTERVAL) {
        redTimer = now;
        digitalWrite(RED_GPIO, !digitalRead(RED_GPIO));
    }

    // YELLOW
    if (now - yellowTimer >= YELLOW_INTERVAL) {
        yellowTimer = now;
        digitalWrite(YELLOW_GPIO, !digitalRead(YELLOW_GPIO));
    }

    // GREEN
    if (now - greenTimer >= GREEN_INTERVAL) {
        greenTimer = now;
        digitalWrite(GREEN_GPIO, !digitalRead(GREEN_GPIO));
    }
}