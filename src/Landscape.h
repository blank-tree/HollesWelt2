#pragma once

#include "ofMain.h"
#include "Plane.h"
#define LAND_COUNT 30

class Landscape {
    
public:
    
    Plane* land[LAND_COUNT];
    int next = 0;
    
    Plane* spawn();
    
    void setup();
    void update();
    void draw();
    
    
private:
    
    
    
};
