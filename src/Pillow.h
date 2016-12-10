#pragma once

#include "ofMain.h"

class Pillow {
    
public:
    ofSerial serial;
    bool connected = false;
    
    int forceLeft = 0;
    int forceRight = 0;
    int angleLeft = 0;
    int angleRight = 0;
    
    void setup();
    void update();

    int averageForce();
    
private:
    string readString();
};
