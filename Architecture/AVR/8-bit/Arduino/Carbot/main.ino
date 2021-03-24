#include <Arduino.h>
#include <IRremote.h>
#include <MotorDriver.h>

IRrecv receiver(9);
MotorDriver motorDriver;

void setup()
{
    receiver.enableIRIn();
}

void loop()
{
    forward();
    backward();
    left();
    right();
}

void forward()
{
    motorDriver.motor(1, FORWARD, 255);
    motorDriver.motor(2, FORWARD, 255);
    motorDriver.motor(3, FORWARD, 255);
    motorDriver.motor(4, FORWARD, 255);

    delay(1000);

    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}

void backward()
{
    motorDriver.motor(1, BACKWARD, 255);
    motorDriver.motor(2, BACKWARD, 255);
    motorDriver.motor(3, BACKWARD, 255);
    motorDriver.motor(4, BACKWARD, 255);

    delay(1000);

    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}

void left()
{
    motorDriver.motor(1, FORWARD, 255);
    motorDriver.motor(2, BACKWARD, 255);
    motorDriver.motor(3, BACKWARD, 255);
    motorDriver.motor(4, FORWARD, 255);

    delay(1000);

    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}

void right()
{
    motorDriver.motor(1, BACKWARD, 255);
    motorDriver.motor(2, FORWARD, 255);
    motorDriver.motor(3, FORWARD, 255);
    motorDriver.motor(4, BACKWARD, 255);

    delay(1000);

    motorDriver.motor(1, RELEASE, 0);
    motorDriver.motor(2, RELEASE, 0);
    motorDriver.motor(3, RELEASE, 0);
    motorDriver.motor(4, RELEASE, 0);
}
