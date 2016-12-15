#include "Soundscape.h"

void Soundscape::setup() {
    // load sound files
    white.load("161201-Holles_Welt-Idle.mp3");
    gold.load("161201-Holles_Welt-Gold.mp3");

    // set loop
    white.setLoop(true);
    gold.setLoop(true);

    // play
    white.play();
    gold.play();
}

void Soundscape::update() {
    // set volumes
    white.setVolume((1 - goldness) * volume);
    gold.setVolume(goldness * volume);
}

void Soundscape::reset() {
    goldness = 0;
}
