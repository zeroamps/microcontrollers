#include <Arduino.h>
#include <MotorDriver.h>

#define TURN_SPEED 153
#define DELAY 50

MotorDriver motorDriver;
int speed = 153;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() > 0) {
        switch (Serial.read()) {
        case 'F':
            forward();
            break;
        case 'B':
            backward();
            break;
        case 'L':
            left();
            break;
        case 'R':
            right();
            break;
        case 'S':
            changeSpeed();
            break;
        }
    } else {
        release();
    }
}

void forward()
{
    motorDriver.motor(1, FORWARD, speed);
    motorDriver.motor(2, FORWARD, speed);
    motorDriver.motor(3, FORWARD, speed);
    motorDriver.motor(4, FORWARD, speed);
    delay(DELAY);
}

void backward()
{
    motorDriver.motor(1, BACKWARD, speed);
    motorDriver.motor(2, BACKWARD, speed);
    motorDriver.motor(3, BACKWARD, speed);
    motorDriver.motor(4, BACKWARD, speed);
    delay(DELAY);
}

void left()
{
    motorDriver.motor(1, FORWARD, TURN_SPEED);
    motorDriver.motor(2, BACKWARD, TURN_SPEED);
    motorDriver.motor(3, BACKWARD, TURN_SPEED);
    motorDriver.motor(4, FORWARD, TURN_SPEED);
    delay(DELAY);
}

void right()
{
    motorDriver.motor(1, BACKWARD, TURN_SPEED);
    motorDriver.motor(2, FORWARD, TURN_SPEED);
    motorDriver.motor(3, FORWARD, TURN_SPEED);
    motorDriver.motor(4, BACKWARD, TURN_SPEED);
    delay(DELAY);
}

void release()
{
    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}

void changeSpeed()
{
    if (speed == 153) {
        speed = 191;
    } else if (speed == 191) {
        speed = 255;
    } else {
        speed = 153;
    }
}
