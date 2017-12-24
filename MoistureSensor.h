#ifndef MoistureSensor_h
#define MoistureSensor_h

#include "Arduino.h"

const int MOISTURE_DRY  = 1;
const int MOISTURE_OKAY = 2;
const int MOISTURE_WET  = 3;

class MoistureSensor
{
    public:
        MoistureSensor(int analogPin, int enablePin);

        void begin();
        unsigned int read();
        const int level();

        bool isOkay();
        bool isDry();
        bool isWet();

    protected:
        int analogPin;
        int enablePin;
};

#endif
