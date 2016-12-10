#include "Statehandler.h"

void Statehandler::setup() {
    state = IDLE;
}

void Statehandler::update() {
    totalAngle = (pillow->angleLeft + pillow->angleRight) / 2;
    
    switch(state) {
        case IDLE:
            updateIdle();
            break;
        case SHAKE:
            updateShake();
            break;
        case CLIMAX:
            updateClimax();
            break;
        case FINISH:
            updateFinish();
            break;
        case RESET:
            updateReset();
            break;
    }
}

void Statehandler::updateIdle() {
    // set spawn intensity
    float totalForce = (pillow->forceLeft + pillow->forceRight) / 2;
    snowfall->spawnRate = ofClamp(totalForce / 100.0, 0.025, 1);
    
    // move on if angle has been reached
    if(totalAngle > 90) {
        state = SHAKE;
        return;
    }
    
    if (counter != 0) {
        counter--;
    }
}

void Statehandler::updateShake() {
    // TODO: Map force to snow rate.
    // TODO: Map angles to wind.
    // TODO: Map total to goldness (snow flakes, clouds, landscapes).
    
    // set spawn intensity & drop speed & goldness
    float totalForce = (pillow->forceLeft + pillow->forceRight) / 2;
    snowfall->spawnRate = totalForce / 10.0;
    snowfall->dropSpeed = totalForce / 10.0;
    
    // increase counter
    counter += totalForce / 10;
    float intensity = ofMap(counter, 0, COUNTER_CLIMAX, 0, 1);
    
    // map goldness
    snowfall->goldness = intensity;
    
    // map soundscape
    soundscape->intensity = intensity;
    
    // move on if climax has been reached
    if(counter > COUNTER_CLIMAX) {
        state = CLIMAX;
        counter = 0;
        return;
    }
    
    if (totalAngle < 90) {
        state = IDLE;
//        counter = 0;
        return;
    }
}

void Statehandler::updateClimax() {
    soundscape->intensity = 1;

    // animate flash
    if(counter < 1) {
        counter += FLASH_SPEED_IN;
    } else if(counter < 2) {
        counter += FLASH_SPEED_OUT;
    } else {
        state = FINISH;
        counter = 0;
        return;
    }
}

void Statehandler::updateFinish() {
    counter++;
    
    soundscape->intensity = 1 - (counter / FINISH_TIME);
    
    if(counter > FINISH_TIME) {
        state = RESET;
        return;
    }
}

void Statehandler::updateReset() {
    snowfall->reset();
    snowfall->spawnRate = 0;
    snowfall->dropSpeed = 0;
    snowfall->goldness = 0;

    soundscape->intensity = 0;
    
    counter = 0;
    state = IDLE;
}

string Statehandler::debugString() {
    string str;
    
    switch(state) {
        case IDLE:
            str = "Idle";
            break;
        case SHAKE:
            str = "Shake";
            break;
        case CLIMAX:
            str = "Climax";
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
