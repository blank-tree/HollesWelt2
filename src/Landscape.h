#pragma once

#include "ofMain.h"

#include "Plane.h"

#define LAND_COUNT 10

class Landscape {
    
public:
    
    Plane* land[LAND_COUNT];
    int next = 0;
    
    Plane* spawn();
    
    void setup();
    void update();
    void draw();
    
    void colorGold(int amount);
    
    void testDraw();
    
    
private:
    
    
    
};
