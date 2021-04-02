#include <Arduino.h>
#include <IRremote.h>
#include <MotorDriver.h>

#define TURN_SPEED 153
#define MOTOR_DELAY 100

IRrecv receiver(PIN_A1);
MotorDriver motorDriver;
int speed = 255;

void setup()
{
    receiver.enableIRIn();
}

void loop()
{
    if (receiver.decode()) {
        receiver.resume();

        switch (receiver.results.value) {
        case 0xE0E006F9:
            forward();
            break;
        case 0xE0E08679:
            backward();
            break;
        case 0xE0E0A659:
            left();
            break;
        case 0xE0E046B9:
            right();
            break;
        case 0xE0E0E01F:
            speedUp();
            break;
        case 0xE0E0D02F:
            slowDown();
            break;
        }
    } else {
        release();
    }
}

void forward()
{
    receiver.disableIRIn();
    motorDriver.motor(1, FORWARD, speed);
    motorDriver.motor(2, FORWARD, speed);
    motorDriver.motor(3, FORWARD, speed);
    motorDriver.motor(4, FORWARD, speed);
    receiver.enableIRIn();

    delay(MOTOR_DELAY);
}

void backward()
{
    receiver.disableIRIn();
    motorDriver.motor(1, BACKWARD, speed);
    motorDriver.motor(2, BACKWARD, speed);
    motorDriver.motor(3, BACKWARD, speed);
    motorDriver.motor(4, BACKWARD, speed);
    receiver.enableIRIn();

    delay(MOTOR_DELAY);
}

void left()
{
    receiver.disableIRIn();
    motorDriver.motor(1, FORWARD, TURN_SPEED);
    motorDriver.motor(2, BACKWARD, TURN_SPEED);
    motorDriver.motor(3, BACKWARD, TURN_SPEED);
    motorDriver.motor(4, FORWARD, TURN_SPEED);
    receiver.enableIRIn();

    delay(MOTOR_DELAY);
}

void right()
{
    receiver.disableIRIn();
    motorDriver.motor(1, BACKWARD, TURN_SPEED);
    motorDriver.motor(2, FORWARD, TURN_SPEED);
    motorDriver.motor(3, FORWARD, TURN_SPEED);
    motorDriver.motor(4, BACKWARD, TURN_SPEED);
    receiver.enableIRIn();

    delay(MOTOR_DELAY);
}

void release()
{
    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}

void speedUp()
{
    speed += 20;
    if (speed > 255) {
        speed = 255;
    }
}

void slowDown()
{
    speed -= 20;
    if (speed < 127) {
        speed = 127;
    }
}