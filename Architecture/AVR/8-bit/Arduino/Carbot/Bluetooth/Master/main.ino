#include <Arduino.h>

#define LBUTTON 4
#define RBUTTON 3
#define TBUTTON 2
#define BBUTTON 5

#define X A1
#define Y A0

int x = 0;
int y = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LBUTTON, INPUT_PULLUP);
    pinMode(RBUTTON, INPUT_PULLUP);
    pinMode(TBUTTON, INPUT_PULLUP);
    pinMode(BBUTTON, INPUT_PULLUP);
}

void loop()
{
    x = analogRead(X);
    y = analogRead(Y);

    if (x < 400) {
        Serial.write('L');
        delay(50);
    } else if (x > 600) {
        Serial.write('R');
        delay(50);
    } else if (y < 400) {
        Serial.write('F');
        delay(50);
    } else if (y > 600) {
        Serial.write('B');
        delay(50);
    }

    if (digitalRead(LBUTTON) == LOW) {
        Serial.write('L');
        delay(50);
    } else if (digitalRead(RBUTTON) == LOW) {
        Serial.write('R');
        delay(50);
    } else if (digitalRead(TBUTTON) == LOW) {
        Serial.write('F');
        delay(50);
    } else if (digitalRead(BBUTTON) == LOW) {
        Serial.write('B');
        delay(50);
    }
}
