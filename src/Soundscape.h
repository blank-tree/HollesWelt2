#pragma once

#include "ofMain.h"
#include "Settings.h"

class Soundscape {
    
public:
    float intensity;
    
    void setup();
    void update();
    
private:
    ofSoundPlayer idle;
    ofSoundPlayer gold;
};
