#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"

enum States {IDLE, SHAKE, CLIMAX, RESET};

class Statehandler {

public:
    States state;
    
    void setup();
    void update(Snowfall*, Pillow*);
    
    string stateString();
    
private:
    void updateIdle(Snowfall*, Pillow*);
    void updateShake(Snowfall*, Pillow*);
    void updateClimax(Snowfall*, Pillow*);
    void updateReset(Snowfall*, Pillow*);
};
