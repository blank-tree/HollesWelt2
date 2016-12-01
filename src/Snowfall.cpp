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
        s->setup(dropSpeed, goldness);
        
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
    for(int i = 0; i < FLAKE_COUNT; i++) {
        flakes[i]->draw();
    }
}
