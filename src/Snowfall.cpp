#include "Snowfall.h"

void Snowfall::setup() {
    for(int i=0; i<FLAKE_COUNT; i++) {
        flakes[i] = new(Snowflake);
    }
}

Snowflake* Snowfall::spawn() {
    if(next >= FLAKE_COUNT) {
        next = 0;
    }
    
    Snowflake* s = flakes[next];
    s->setup();
    
    next++;
    
    return s;
}

void Snowfall::update() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        Snowflake* s = flakes[i];
        
        s->update();
    }
}

void Snowfall::draw() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        Snowflake* s = flakes[i];
        
        if(!s->active) {
            continue;
        }
        
        int grey = 255;
        
        if (s->restingCounter > 0) {
            grey = ofMap(s->restingCounter, 0, FLAKE_LIFETIME, 255, 0);
        }
        
        ofSetColor(grey, grey, grey);
        ofFill();
        
        s->draw();
    }
}
