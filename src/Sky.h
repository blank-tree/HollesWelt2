#pragma once

#include "ofMain.h"

#include "Settings.h"

class Sky {
    
public:
    // between 0 and 1
    float intensity;
    float goldness;
    
    void setup();
    void update();
    void draw();
    
    void testDraw();
    
private:

};
