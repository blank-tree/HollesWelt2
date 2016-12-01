#pragma once

#include "ofMain.h"

class Snowflake : public ofNode{
    public:
        void setup(float dropSpeed, float goldness);
        void update(ofVec3f wind);
        void draw();
        void reset();
    
    private:
        bool active;
    
        int xRange;
        int yRange;
        int zRange;
    
        ofVec3f movement;
        float goldness;
    
        ofVec3f decideStart();
        ofVec3f decideMovement(float);
};
