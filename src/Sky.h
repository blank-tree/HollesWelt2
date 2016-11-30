#pragma once

#include "ofMain.h"
#include "Cloud.h"

#define CLOUD_ARRAY_SIZE 30

class Sky {
    
public:
    
    
    void setup();
    void update();
    void draw();
    
private:
    
    Cloud* clouds[CLOUD_ARRAY_SIZE];
    
};
