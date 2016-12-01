#pragma once

#include "ofMain.h"

#include "Snowflake.h"
#include "Settings.h"

class Snowfall {
    
public:
    // how many new flakes per frame
    float spawnRate = 0;
    
    // how many pixels to drop per frame
    float dropSpeed = 1;
    
    ofVec3f wind;
    
    void setup();
    void update();
    void draw();
    
private:
    Snowflake* flakes[FLAKE_COUNT];
    int next = 0;
    float counter = 0;
};
