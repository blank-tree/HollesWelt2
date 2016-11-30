#pragma once

#include "ofMain.h"

enum states {IDLE, ENTER, GOLD, LEAVE};

class Statehandler {

public:
    
    bool active;
    states currentState;
    
    void setup();
    void update();
    void nextState();
    
    int getStateNo();
    
};
