#pragma once

#include "ofMain.h"

class Landscape {
    
public:
    // between 0 and 1
    float intensity;
    
    void setup();
    void update();
    void draw();
    
private:
    
    float goldness [3];
    
};
