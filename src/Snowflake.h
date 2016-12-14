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
        bool active;
        float endY;
        ofVec3f movement;
        float goldness;
};
