#include "Soundscape.h"

void Soundscape::setup() {
    
    idleVolume = 1;
    goldVolume = 0;
    
    idle.load("161201-Holles_Welt-Idle.mp3");
    gold.load("161201-Holles_Welt-Gold.mp3");
    
    idle.setLoop(true);
    gold.setLoop(true);
    
    idle.play();
    gold.play();
    
    this->update();
}

void Soundscape::update() {
    idle.setVolume(idleVolume);
    gold.setVolume(goldVolume);
}

void Soundscape::intensity(float intesity) {
    
}
