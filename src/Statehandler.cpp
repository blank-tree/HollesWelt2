#include "Statehandler.h"

void Statehandler::setup() {
    state = IDLE;
}

void Statehandler::update(Snowfall* snowfall, Pillow* pillow) {
    switch(state) {
        case IDLE:
            updateIdle(snowfall, pillow);
            break;
        case ENTER:
            updateEnter(snowfall, pillow);
            break;
        case GOLD:
            updateGold(snowfall, pillow);
            break;
        case LEAVE:
            updateLeave(snowfall, pillow);
            break;
    }
}

void Statehandler::updateIdle(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Map angles to cloud movements.
    // TODO: Change to Enter on success.
    
    snowfall->spawnRate = 0.05;
    snowfall->spawnRate = pillow->forceLeft * pillow->forceRight * 10;
}

void Statehandler::updateEnter(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Map force to snow rate.
    // TODO: Change to GOLD on success.
    // TODO: Change to Leave on fail.
}

void Statehandler::updateGold(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Flash gold.
    // TODO: Change to LEAVE.
}

void Statehandler::updateLeave(Snowfall* snowfall, Pillow* pillow) {
    // TODO: Reset sim.
    // TODO: Change to IDLE.
}
