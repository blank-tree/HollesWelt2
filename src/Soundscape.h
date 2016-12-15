#pragma once

#include "ofMain.h"
#include "Settings.h"

class Soundscape {
    
public:
    float intensity = 0;
    
    void setup();
    void update();
    void reset();
    
private:
    ofSoundPlayer white;
    ofSoundPlayer gold;
};
