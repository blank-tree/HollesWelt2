#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Sky.h"
#include "Flash.h"
#include "Soundscape.h"

enum States {IDLE, SHAKE, CLIMAX, FINISH, RESET};

class Statehandler {

public:
    Snowfall* snowfall;
    Pillow* pillow;
    Sky* sky;
    Flash* flash;
    Soundscape* soundscape;
    
    void setup();
    void update();
    
    string debugString();
    
private:
    States state;
    float counter;
    float totalAngle;
    
    void updateIdle();
    void updateShake();
    void updateClimax();
    void updateFinish();
    void updateReset();
};
