#include <Arduino.h>
#include <MotorDriver.h>

#define TURN_SPEED 153
#define MOTOR_DELAY 50

MotorDriver motorDriver;
int speed = 255;

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
        case '>':
            speedUp();
            break;
        case '<':
            slowDown();
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
    delay(MOTOR_DELAY);
}

void backward()
{
    motorDriver.motor(1, BACKWARD, speed);
    motorDriver.motor(2, BACKWARD, speed);
    motorDriver.motor(3, BACKWARD, speed);
    motorDriver.motor(4, BACKWARD, speed);
    delay(MOTOR_DELAY);
}

void left()
{
    motorDriver.motor(1, FORWARD, TURN_SPEED);
    motorDriver.motor(2, BACKWARD, TURN_SPEED);
    motorDriver.motor(3, BACKWARD, TURN_SPEED);
    motorDriver.motor(4, FORWARD, TURN_SPEED);
    delay(MOTOR_DELAY);
}

void right()
{
    motorDriver.motor(1, BACKWARD, TURN_SPEED);
    motorDriver.motor(2, FORWARD, TURN_SPEED);
    motorDriver.motor(3, FORWARD, TURN_SPEED);
    motorDriver.motor(4, BACKWARD, TURN_SPEED);
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