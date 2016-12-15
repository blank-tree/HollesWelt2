#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Soundscape.h"

enum States {DEFAULT, FINISH, RESET};

class Statehandler {

public:
    ofCamera* cam;
    Snowfall* snowfall;
    Pillow* pillow;
    Soundscape* soundscape;
    
    void setup();
    void update();
    
    string debugString();
    
private:
    States state = DEFAULT;
    float counter = 0;
    
    void updateDefault();
    void updateFinish();
    void updateReset();
};
