#pragma once

#include "ofMain.h"

#include "Snowflake.h"

#define FLAKE_COUNT 10000
#define FLAKE_START_Y 1000 // TODO: Other startingpoint

class Snowfall {
    
public:
    float spawnRate = 0;
    ofVec3f wind;
    
    void setup();
    void update();
    void draw();
    
private:
    Snowflake* flakes[FLAKE_COUNT];
    int next = 0;
    float counter = 0;
};
