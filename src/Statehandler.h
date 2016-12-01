#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Flash.h"

enum States {IDLE, SHAKE, CLIMAX, RESET};

class Statehandler {

public:
    States state;
    
    void setup();
    void update(Snowfall*, Pillow*, Flash*);
    
    string stateString();
    
private:
    float counter;
    
    void updateIdle(Snowfall*, Pillow*, Flash*);
    void updateShake(Snowfall*, Pillow*, Flash*);
    void updateClimax(Snowfall*, Pillow*, Flash*);
    void updateReset(Snowfall*, Pillow*, Flash*);
};
