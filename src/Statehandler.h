#pragma once

#include "ofMain.h"

#include "Snowfall.h"
#include "Pillow.h"

enum states {IDLE, ENTER, GOLD, LEAVE};

class Statehandler {

public:
    states state;
    
    void setup();
    void update(Snowfall*, Pillow*);
    
private:
    void updateIdle(Snowfall*, Pillow*);
    void updateEnter(Snowfall*, Pillow*);
    void updateGold(Snowfall*, Pillow*);
    void updateLeave(Snowfall*, Pillow*);
};
