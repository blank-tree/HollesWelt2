#pragma once

#include "ofMain.h"

class Snowflake : public ofSpherePrimitive{
    public:
        int restingCounter = 0;
        int startingCounter = 0;
        bool active = false;
};
