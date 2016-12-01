#pragma once

#include "ofMain.h"

class Snowflake : public ofNode{
    public:
        int restingCounter;
        int startingCounter;
        bool active;
    
        void setup(float);
        void update(ofVec3f);
        void draw();
    
    private:
        int xRange;
        int yRange;
        int zRange;
    
        ofVec3f movement;
    
        ofVec3f decideStart();
        ofVec3f decideMovement(float);
};
