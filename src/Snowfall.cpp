#include "Snowfall.h"

void Snowfall::setup() {
    for(int i=0; i<FLAKE_COUNT; i++) {
        flakes[i] = new(Snowflake);
    }
}

void Snowfall::update() {
    // increment counter
    counter += spawnRate;

    // spawn new flake if counter has been reached
    while(counter >= 1) {
        // reset on overflow
        if(next >= FLAKE_COUNT) {
            next = 0;
        }

        // get next flake
        Snowflake* s = flakes[next];
        s->setup(dropSpeed, goldness);

        // set counters
        next++;
        counter -= 1;
    }
    
    // update all flakes
    for(int i = 0; i < FLAKE_COUNT; i++) {
        flakes[i]->update(wind);
    }
}

void Snowfall::draw() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        flakes[i]->draw();
    }
}

void Snowfall::reset() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        flakes[i]->reset();
    }
}
