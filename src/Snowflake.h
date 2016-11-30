#pragma once

#include "ofMain.h"

#define FLAKE_LIFETIME 500

class Snowflake : public ofSpherePrimitive{
    public:
        int restingCounter;
        int startingCounter;
        bool active;
    
        void setup();
        void update();
    
    private:
    
        int xRange;
        int yRange;
        int zRange;
        ofVec3f movement;
    
        ofVec3f decideStart();
        ofVec3f decideMovement();
    
};
