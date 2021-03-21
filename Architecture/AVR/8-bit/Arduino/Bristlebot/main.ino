#include <Arduino.h>
#include <IRremote.h>

#define MOTOR_DRIVER 9
IRrecv receiver(11);
int speed = 0;

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
            speed = 0;
            break;

        case 0xE0E020DF: // Speed 1
            analogWrite(MOTOR_DRIVER, 100);
            speed = 1;
            break;

        case 0xE0E0A05F: // Speed 2
            analogWrite(MOTOR_DRIVER, 150);
            speed = 2;
            break;
        }

        delay(1000);
        receiver.resume();
    }

    stopMotorIfStuck(speed);
    delay(50);
}

void stopMotorIfStuck(int speed)
{
    switch (speed) {
    case 1:
        if (analogRead(A3) < 30) {
            delay(1000);
            if (analogRead(A3) < 30) {
                analogWrite(MOTOR_DRIVER, 0);
                speed = 0;
            }
        }
        break;

    case 2:
        if (analogRead(A3) < 57) {
            delay(1000);
            if (analogRead(A3) < 57) {
                analogWrite(MOTOR_DRIVER, 0);
                speed = 0;
            }
        }
        break;
    }
}