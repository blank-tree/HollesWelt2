#include "Soundscape.h"

void Soundscape::setup() {
    idle.load("161201-Holles_Welt-Idle.mp3");
    gold.load("161201-Holles_Welt-Gold.mp3");
    
    idle.setLoop(true);
    gold.setLoop(true);
    
    idle.play();
    gold.play();
    
    this->update();
}

void Soundscape::update() {
    idle.setVolume(1 - intensity);
    gold.setVolume(intensity);
}
