#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Sky.h"
#include "Flash.h"

enum States {IDLE, SHAKE, CLIMAX, RESET};

class Statehandler {

public:
    States state;
    
    void setup();
    void update(Snowfall*, Pillow*, Sky*, Flash*);
    
    string stateString();
    
private:
    float counter;
    
    void updateIdle(Snowfall*, Pillow*, Sky*, Flash*);
    void updateShake(Snowfall*, Pillow*, Sky*, Flash*);
    void updateClimax(Snowfall*, Pillow*, Sky*, Flash*);
    void updateReset(Snowfall*, Pillow*, Sky*, Flash*);
};
