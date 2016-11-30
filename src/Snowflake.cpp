//
//  SnowSphere.cpp
//  HollesWelt
//
//  Created by Fernando Obieta on 29.11.16.
//

#include "Snowflake.h"

// PUBLIC ---------------------------------

void Snowflake::setup() {
    restingCounter = 0;
    startingCounter = 0;
    
    setRadius(10);
    setResolution(10);
    active = true;
    
    xRange = ofGetWindowWidth();
    yRange = ofGetWindowHeight();
    zRange = ofGetWindowWidth();
    
    this->setPosition(decideStart());
    movement = this->decideMovement();
    
    this->update();
}

void Snowflake::update() {
    if(!active) {
        return;
    }
    
    if (getY() < 0) {
        restingCounter++;
        
        if (restingCounter > FLAKE_LIFETIME) {
            active = false;
            return;
        }
        
        restingCounter++;
        return;
    }
    
    this->setPosition(this->getPosition() + movement);

}

// PRIVATE ---------------------------------

ofVec3f Snowflake::decideStart() {
    float startX = (float)((rand() % xRange) - xRange / 2);
    float startY = yRange;
    float startZ = (float)((rand() % zRange) - zRange / 2);
    return ofVec3f(startX, startY, startZ);
}

ofVec3f Snowflake::decideMovement() {
    float targetX = (ofRandom(1) - 0.5) / 1;
    float targetY = -2;
    float targetZ = (ofRandom(1) - 0.5) / 1;
    return ofVec3f(targetX, targetY, targetZ);
}
