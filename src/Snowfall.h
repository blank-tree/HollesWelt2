#pragma once

#include "ofMain.h"

#include "Snowflake.h"
#include "Settings.h"

class Snowfall {
    
public:
    float spawnRate = 0;
    float goldness = 0;
    float dropSpeed = 0;
    ofVec3f wind = {0, 0, 0};
    
    void setup();
    void update();
    void draw();
    void reset();
    
private:
    Snowflake* flakes[FLAKE_COUNT];
    int next = 0;
    float counter = 0;
};
