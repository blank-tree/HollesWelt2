#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Soundscape.h"

enum States {DEFAULT, CLIMAX, FINISH, RESET};

class Statehandler {

public:
    Snowfall* snowfall;
    Pillow* pillow;
    Soundscape* soundscape;
    
    void setup();
    void update();
    
    string debugString();
    
private:
    States state;
    float counter;
    
    void updateDefault();
    void updateClimax();
    void updateFinish();
    void updateReset();
};
