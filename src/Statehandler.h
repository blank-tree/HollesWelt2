#pragma once

#include "ofMain.h"

class Statehandler {
    
public:
    
    bool active;
    int stateNo;
    
    void setup();
    void update();
    void nextState();
    
    int getStateNo();
    
};
