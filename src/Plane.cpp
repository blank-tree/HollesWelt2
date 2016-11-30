#include "Plane.h"

void Plane::setup() {
    y = 20;
    z = 0;
    color = ofColor(171,189,255);
    direction = ofRandom(1) < 0.5;
    active = true;
    fadeActive = false;
    fadeState = 0;
}

void Plane::update() {
    // TODO: set position
    
}

void Plane::draw() {
    
    colorUpdate();
    
    if (!active) {
        fadeActive = false;
        return;
    }
    
    // TODO: draw the damn thing
}

void Plane::fade(bool fadeActive) {
    this->fadeActive = fadeActive;
    
}

void Plane::colorUpdate() {
    if (fadeActive) {
        fadeState = fadeState + 1 < 100 ? fadeState + 1 : 100;
    } else {
        fadeState = fadeState - 1 > 0 ? fadeState - 1 : 0;
    }
    
    int newRed = (int)ofMap(fadeState, 0, 99, 171, 255);
    int newGreen = (int)ofMap(fadeState, 0, 99, 189, 157);
    int newBlue = (int)ofMap(fadeState, 0, 99, 255, 0);
    
    color = ofColor(newRed, newGreen, newBlue);
}
