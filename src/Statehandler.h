#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"
#include "Flash.h"
#include "Soundscape.h"

#define SHAKE_MAX 1000

enum States {IDLE, SHAKE, CLIMAX, RESET};

class Statehandler {

public:
    States state;
    
    void setup();
    void update(Snowfall*, Pillow*, Flash*, Soundscape*);
    
    string stateString();
    
private:
    float counter;
    
    void updateIdle(Snowfall*, Pillow*, Flash*, Soundscape*);
    void updateShake(Snowfall*, Pillow*, Flash*, Soundscape*);
    void updateClimax(Snowfall*, Pillow*, Flash*, Soundscape*);
    void updateReset(Snowfall*, Pillow*, Flash*, Soundscape*);
};
