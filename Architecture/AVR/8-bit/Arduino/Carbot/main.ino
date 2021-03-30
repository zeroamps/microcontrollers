#include <Arduino.h>
#include <IRremote.h>
#include <MotorDriver.h>

#define SPEED1 255
#define SPEED2 153
#define DELAY 50

IRrecv receiver(9);
MotorDriver motorDriver;

void setup()
{
    Serial.begin(115200);
    receiver.enableIRIn();
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
        }
    } else {
        release();
    }
}

void forward()
{
    motorDriver.motor(1, FORWARD, SPEED1);
    motorDriver.motor(2, FORWARD, SPEED1);
    motorDriver.motor(3, FORWARD, SPEED1);
    motorDriver.motor(4, FORWARD, SPEED1);
    delay(DELAY);
}

void backward()
{
    motorDriver.motor(1, BACKWARD, SPEED1);
    motorDriver.motor(2, BACKWARD, SPEED1);
    motorDriver.motor(3, BACKWARD, SPEED1);
    motorDriver.motor(4, BACKWARD, SPEED1);
    delay(DELAY);
}

void left()
{
    motorDriver.motor(1, FORWARD, SPEED2);
    motorDriver.motor(2, BACKWARD, SPEED2);
    motorDriver.motor(3, BACKWARD, SPEED2);
    motorDriver.motor(4, FORWARD, SPEED2);
    delay(DELAY);
}

void right()
{
    motorDriver.motor(1, BACKWARD, SPEED2);
    motorDriver.motor(2, FORWARD, SPEED2);
    motorDriver.motor(3, FORWARD, SPEED2);
    motorDriver.motor(4, BACKWARD, SPEED2);
    delay(DELAY);
}

void release()
{
    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}