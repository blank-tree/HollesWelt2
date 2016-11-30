#pragma once

#include "ofMain.h"

#include "Snowflake.h"

#define FLAKE_COUNT 10000
#define FLAKE_LIFETIME 500

class Snowfall {
    
public:
    Snowflake* flakes[FLAKE_COUNT];
    int nextActivation = 0;
    
    void spawn();
    Snowflake* activate();
    
    void setup();
    void update();
    void draw();
};
