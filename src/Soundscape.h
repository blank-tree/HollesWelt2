#pragma once

#include "ofMain.h"
#include "Settings.h"

class Soundscape {
    
public:
    void setup();
    void update();
    void intensity(float intesity);
    
private:
    ofSoundPlayer idle;
    ofSoundPlayer gold;
    float idleVolume;
    float goldVolume;
};
