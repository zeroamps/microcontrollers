#include <Arduino.h>

#define X A1
#define Y A0 

int x = 0;
int y = 0;

void setup()
{
    Serial.begin(115200);
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
}
