#include "Snowfall.h"

void Snowfall::setup() {
    for(int i=0; i<FLAKE_COUNT; i++) {
        flakes[i] = new(Snowflake);
    }
}

void Snowfall::update() {
    // spawn new flake if counter has been reached
    counter += spawnRate;
    while(counter >= 1) {
        if(next >= FLAKE_COUNT) {
            next = 0;
        }
        
        Snowflake* s = flakes[next];
        s->setup(dropSpeed);
        
        next++;
        counter -= 1;
    }
    
    // update all flakes
    for(int i = 0; i < FLAKE_COUNT; i++) {
        Snowflake* s = flakes[i];
        
        s->update(wind);
    }
}

void Snowfall::draw() {
    // TODO: Move drawing of flakes to Snowflake.
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
