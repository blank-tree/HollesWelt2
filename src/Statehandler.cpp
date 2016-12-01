#include "Statehandler.h"

void Statehandler::setup() {
    state = IDLE;
}

void Statehandler::update(Snowfall* snowfall, Pillow* pillow, Sky* sky, Flash* flash, Soundscape* soundscape) {
    switch(state) {
        case IDLE:
            updateIdle(snowfall, pillow, sky, flash, soundscape);
            break;
        case SHAKE:
            updateShake(snowfall, pillow, sky, flash, soundscape);
            break;
        case CLIMAX:
            updateClimax(snowfall, pillow, sky, flash, soundscape);
            break;
        case RESET:
            updateReset(snowfall, pillow, sky, flash, soundscape);
            break;
    }
}

void Statehandler::updateIdle(Snowfall* snowfall, Pillow* pillow, Sky* sky, Flash* flash, Soundscape* soundscape) {
    // TODO: Map angles to cloud movements.
    // TODO: Map force to snow rate.
    // TODO: Change to SHAKE on success (over 90 degrees).
    
    snowfall->spawnRate = pillow->forceLeft / 100.0;
    snowfall->dropSpeed = pillow->forceLeft / 5.0;
    snowfall->goldness = pillow->forceRight / 100.0;
    
    // set sky intensity
    float totalAngle = (pillow->angleLeft + pillow->angleRight) / 2;
    sky->intensity = ofClamp(totalAngle / 90.0, 0, 1);
    
    // move on if angle has been reached
    if(totalAngle > 90) {
        sky->intensity = 1;
        
        state = SHAKE;
        return;
    }
}

void Statehandler::updateShake(Snowfall* snowfall, Pillow* pillow, Sky* sky, Flash* flash, Soundscape* soundscape) {
    // TODO: Map force to snow rate.
    // TODO: Map angles to wind.
    // TODO: Map total to goldness (snow flakes, clouds, landscapes).
    // TODO: Change to CLIMAX on success.
    // TODO: Change to RESET on fail.
    
    //snowfall->spawnRate = pillow->forceLeft * pillow->forceRight * 10;
    
    counter = counter + 1 < SHAKE_MAX ? counter + 1 : SHAKE_MAX;
    soundscape->intensity(ofMap(counter, 0, SHAKE_MAX, 0, 1));
}

void Statehandler::updateClimax(Snowfall* snowfall, Pillow* pillow, Sky* sky, Flash* flash, Soundscape* soundscape) {
    soundscape->intensity(1);

    if(counter < 1) {
        counter += FLASH_SPEED_IN;
        flash->intensity = counter;
    } else if(counter < 2) {
        counter += FLASH_SPEED_OUT;
        flash->intensity = 1 - (counter - 1);
    } else {
        state = RESET;
        return;
    }
}

void Statehandler::updateReset(Snowfall* snowfall, Pillow* pillow, Sky* sky, Flash* flash, Soundscape* soundscape) {
    flash->intensity = 0;
    soundscape->intensity(0);
    
    state = IDLE;
}

string Statehandler::stateString() {
    switch(state) {
        case IDLE:
            return "Idle";
        case SHAKE:
            return "Shake";
        case CLIMAX:
            return "Climax";
        case RESET:
            return "Reset";
    }
}
