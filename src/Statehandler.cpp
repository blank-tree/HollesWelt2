#include "Statehandler.h"
#include "Utils.h"

void Statehandler::setup() {
    state = DEFAULT;
}

void Statehandler::update() {
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
    int tilt = pillow->betterTilt();

    // set spawn intensity
    snowfall->spawnRate = ofClamp(pillow->averageForce() / 10.0, 0.05, 10);
    snowfall->dropSpeed = ofClamp(pillow->averageForce() / 10.0, 0, 20);
    snowfall->wind = ofVec3f(tilt / 25, abs(tilt) / -50, 0);
    
    // increase counter
    counter += pillow->averageForce() / 10;
    float intensity = ofMap(counter, 0, COUNTER_FINISH, 0, 1);
    
    // map goldness
    snowfall->goldness = intensity;
    
    // map soundscape
    soundscape->intensity = intensity;
    
    // move on if climax has been reached
    if(counter > COUNTER_FINISH) {
        state = FINISH;
        counter = 0;
        return;
    }
}

void Statehandler::updateFinish() {
    counter++;
    
    soundscape->intensity = 1 - (counter / FINISH_TIME);

    // calculate cam movement
    float camX = easeInQuart(counter / FINISH_TIME, 1500, -3000, 1);
    ofVec3f pos = cam->getPosition();
    cam->setPosition(camX, pos.y, pos.z);
    
    if(counter > FINISH_TIME) {
        state = RESET;
        counter = 0;
        return;
    }
}

void Statehandler::updateReset() {
    snowfall->reset();
    snowfall->spawnRate = 0;
    snowfall->dropSpeed = 0;
    snowfall->goldness = 0;

    soundscape->intensity = 0;

    ofVec3f pos = cam->getPosition();
    cam->setPosition(1500, pos.y, pos.z);
    
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
