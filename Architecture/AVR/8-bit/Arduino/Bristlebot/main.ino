#include <Arduino.h>
#include <IRremote.h>

#define MOTOR_DRIVER 9
IRrecv receiver(11);

void setup()
{
    analogWrite(MOTOR_DRIVER, 0);
    receiver.enableIRIn();
}

void loop()
{
    if (receiver.decode()) {
        switch (receiver.results.value) {
        case 0xE0E040BF: // Turn OFF
            analogWrite(MOTOR_DRIVER, 0);
            break;

        case 0xE0E020DF: // Speed 1
            analogWrite(MOTOR_DRIVER, 100);
            break;

        case 0xE0E0A05F: // Speed 2
            analogWrite(MOTOR_DRIVER, 150);
            break;

        case 0xE0E0609F: // Speed 3
            analogWrite(MOTOR_DRIVER, 200);
            break;
        }

        delay(250);
        receiver.resume();
    }
}
