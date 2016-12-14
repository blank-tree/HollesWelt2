#pragma once

#include "ofMain.h"

#include "Snowflake.h"
#include "Settings.h"

class Snowfall {
    
public:
    float spawnRate;
    float goldness;
    float dropSpeed;
    ofVec3f wind;
    
    void setup();
    void update();
    void draw();
    void reset();
    
private:
    Snowflake* flakes[FLAKE_COUNT];
    int next = 0;
    float counter = 0;
};
