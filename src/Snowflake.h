#pragma once

#include "ofMain.h"

#define FLAKE_LIFETIME 500

class Snowflake : public ofNode{
    public:
        int restingCounter;
        int startingCounter;
        bool active;
    
        void setup();
        void update(ofVec3f);
        void draw();
    
    private:
        int xRange;
        int yRange;
        int zRange;
        ofVec3f movement;
    
        ofVec3f decideStart();
        ofVec3f decideMovement();
};
