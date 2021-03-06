#include "Statehandler.h"
#include "Utils.h"

void Statehandler::setup() {
    state = DEFAULT;
}

void Statehandler::update() {
    // call sub handlers
    switch(state) {
        case DEFAULT:
            updateDefault();
            break;
        case FINISH:
            updateFinish();
            break;
        case RESET:
            updateReset();
            break;
    }
}

void Statehandler::updateDefault() {
    // decrease counter
    if(counter - COUNTER_DECREMENT > 0) {
        counter -= COUNTER_DECREMENT;
    }

    // increase counter
    counter += pillow->averageForce() / 10;

    // get tilt
    int tilt = pillow->smoothTilt();

    // update snowfall
    snowfall->spawnRate = ofClamp((float)(pillow->averageForce() / 10.0), 0.05, 10);
    snowfall->dropSpeed = ofClamp((float)(pillow->averageForce() / 7.5), 0, 15);
    snowfall->wind = ofVec3f(tilt / 25, abs(tilt) / -50, 0);

    // calculate goldness & volume
    float goldness = ofMap(counter, 0, CLIMAX_TOTAL_FORCE, 0, 1);
    float volume = ofMap(counter, 0, CLIMAX_TOTAL_FORCE / 10, 0.25, 1, true);
    
    // set goldness and goldness
    snowfall->goldness = goldness;
    soundscape->goldness = goldness;
    soundscape->volume = volume;
    
    // move on if climax has been reached
    if(counter > CLIMAX_TOTAL_FORCE) {
        state = FINISH;
        counter = 0;
        return;
    }
}

void Statehandler::updateFinish() {
    // increment counter
    counter++;

    // calculate time
    float t = counter / FINISH_FRAMES;

    // decrease soundscape
    soundscape->goldness = 1 - t;
    soundscape->volume = ofMap(t, 0, 1, 1, 0.25);

    // calculate cam movement
    float x = easeInQuart(t, 1500, -3000, 1);
    cam->setPosition(x, cam->getY(), cam->getZ());

    // change state if reached finish
    if(counter > FINISH_FRAMES) {
        state = RESET;
        counter = 0;
        return;
    }
}

void Statehandler::updateReset() {
    // reset snowfall and soundscape
    snowfall->reset();
    soundscape->reset();

    // set camera position
    cam->setPosition(1500, cam->getY(), cam->getZ());

    // change state
    counter = 0;
    state = DEFAULT;
}

string Statehandler::debugString() {
    string str;
    
    switch(state) {
        case DEFAULT:
            str = "Default";
            break;
        case FINISH:
            str = "Finish";
            break;
        case RESET:
            str = "Reset";
            break;
    }
    
    return str + " (" + ofToString(counter) + ")";
}
