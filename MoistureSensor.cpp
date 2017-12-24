#include "MoistureSensor.h"

MoistureSensor::MoistureSensor (int analogPin, int enablePin)
{
    this->analogPin = analogPin;
    this->enablePin = enablePin;
}

void
MoistureSensor::begin()
{
    pinMode(analogPin, INPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW);
}

unsigned int 
MoistureSensor::read()
{
    digitalWrite(enablePin, HIGH);
    delay(10);
    unsigned int moisture = analogRead(analogPin);
    digitalWrite(enablePin, LOW);
    return moisture;
}


const int
MoistureSensor::level() 
{
    unsigned int moisture = read();
    if (moisture < 300) {
        return MOISTURE_WET;
    } else if (moisture < 500) {
        return MOISTURE_OKAY;
    } else {
        return MOISTURE_DRY;
    }
}

bool
MoistureSensor::isOkay()
{
    return level() == MOISTURE_OKAY;
}

bool
MoistureSensor::isDry()
{
    return level() == MOISTURE_DRY;
}

bool
MoistureSensor::isWet()
{
    return level() == MOISTURE_WET;
}

