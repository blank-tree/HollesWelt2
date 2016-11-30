#include "Statehandler.h"

void Statehandler::setup() {
    state = IDLE;
}

void Statehandler::update(Snowfall* snowfall, Pillow* pillow) {
    switch(state) {
        case IDLE:
            updateIdle(snowfall, pillow);
            break;
        case SHAKE:
            updateShake(snowfall, pillow);
            break;
        case CLIMAX:
            updateClimax(snowfall, pillow);
            break;
        case RESET:
            updateReset(snowfall, pillow);
            break;
    }
}

void Statehandler::updateIdle(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Map angles to cloud movements.
    // TODO: Map force to snow rate.
    // TODO: Change to SHAKE on success (over 90 degrees).
    
    // snowfall->spawnRate = 0.05;
    snowfall->spawnRate = pillow->forceLeft * pillow->forceRight * 10;
}

void Statehandler::updateShake(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Map force to snow rate.
    // TODO: Map angles to wind.
    // TODO: Map total to goldness.
    // TODO: Change to CLIMAX on success.
    // TODO: Change to RESET on fail.
}

void Statehandler::updateClimax(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Flash gold.
    // TODO: Change to LEAVE.
}

void Statehandler::updateReset(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Reset sim.
    // TODO: Change to IDLE.
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
