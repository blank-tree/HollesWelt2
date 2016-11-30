#pragma once

#include "ofMain.h"

class Plane {
    
public:
    float y;
    float z;
    ofColor color;
    bool direction;
    bool active;
    bool fadeActive;
    
    void setup();
    void update();
    void draw();
    void fade(bool fadeActive);
    
private:
    int fadeState;
    
    void colorUpdate();
};
