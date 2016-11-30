#include "Sky.h"

void Sky::setup() {
    
    for (int i = 0; i < CLOUD_ARRAY_SIZE; i++) {
        clouds[i] = new (Cloud);
        clouds[i]->setup();
    }
    
}

void Sky::update() {
    
    for (int i = 0; i < CLOUD_ARRAY_SIZE; i++) {
        if (clouds[i]->active) {
            clouds[i]->update();
        }
    }
    
}

void Sky::draw() {
    for (int i = 0; i < CLOUD_ARRAY_SIZE; i++) {
        if (clouds[i]->active) {
            clouds[i]->draw();
        }
    }
}
