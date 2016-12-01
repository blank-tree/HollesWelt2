#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Sky.h"
#include "Flash.h"
#include "Soundscape.h"

#define SHAKE_MAX 1000

enum States {IDLE, SHAKE, CLIMAX, RESET};

class Statehandler {

public:
    States state;
    
    Snowfall* snowfall;
    Pillow* pillow;
    Sky* sky;
    Flash* flash;
    Soundscape* soundscape;
    
    void setup();
    void update();
    
    string stateString();
    
private:
    float counter;
    
    void updateIdle();
    void updateShake();
    void updateClimax();
    void updateReset();
};
