#include "Statehandler.h"

void Statehandler::setup() {
    state = CLIMAX;
}

void Statehandler::update(Snowfall* snowfall, Pillow* pillow, Flash* flash) {
    switch(state) {
        case IDLE:
            updateIdle(snowfall, pillow, flash);
            break;
        case SHAKE:
            updateShake(snowfall, pillow, flash);
            break;
        case CLIMAX:
            updateClimax(snowfall, pillow, flash);
            break;
        case RESET:
            updateReset(snowfall, pillow, flash);
            break;
    }
}

void Statehandler::updateIdle(Snowfall* snowfall, Pillow* pillow, Flash* flash) {
    // TODO: Map angles to cloud movements.
    // TODO: Map force to snow rate.
    // TODO: Change to SHAKE on success (over 90 degrees).
    
    // snowfall->spawnRate = 0.05;
    snowfall->spawnRate = pillow->forceLeft * pillow->forceRight * 10;
}

void Statehandler::updateShake(Snowfall* snowfall, Pillow* pillow, Flash* flash) {
    // TODO: Map force to snow rate.
    // TODO: Map angles to wind.
    // TODO: Map total to goldness (snow flakes, clouds, landscapes).
    // TODO: Change to CLIMAX on success.
    // TODO: Change to RESET on fail.
}

void Statehandler::updateClimax(Snowfall* snowfall, Pillow* pillow, Flash* flash) {
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

void Statehandler::updateReset(Snowfall* snowfall, Pillow* pillow, Flash* flash) {
    flash->intensity = 0;
    
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
