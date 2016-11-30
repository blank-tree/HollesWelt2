#pragma once

#include "ofMain.h"

#include "Snowflake.h"

#define FLAKE_COUNT 10000
#define FLAKE_LIFETIME 500
#define FLAKE_START_Y 1000

class Snowfall {
    
public:
    Snowflake* flakes[FLAKE_COUNT];
    int next = 0;
    
    Snowflake* spawn();
    
    void setup();
    void update();
    void draw();
};
