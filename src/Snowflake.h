#pragma once

#include "ofMain.h"

void drawSnowflake(ofColor);

class Snowflake : public ofNode{
    public:
        void setup(float dropSpeed, float goldness);
        void update(ofVec3f wind);
        void draw();
        void reset();
    
    private:
        bool active = false;
        float endY = 0;
        ofVec3f movement = {0, 0, 0};
        float goldness = 0;
};
