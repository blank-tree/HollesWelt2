//
//  SnowSphere.cpp
//  HollesWelt
//
//  Created by Fernando Obieta on 29.11.16.
//

#include "Snowflake.h"
#include "Settings.h"

// PUBLIC ---------------------------------

void Snowflake::setup(float dropSpeed) {
    restingCounter = 0;
    startingCounter = 0;
    
    active = true;
    
    xRange = ofGetWindowWidth();
    yRange = ofGetWindowHeight();
    zRange = ofGetWindowWidth();
    
    this->setPosition(decideStart());
    movement = this->decideMovement(dropSpeed);
    
    this->update(ofVec3f(0, 0, 0));
}

void Snowflake::update(ofVec3f wind) {
    if(!active) {
        return;
    }
    
    // slow down snow flakes and enforce normal drop speed
    if(movement.y < FLAKE_NORMAL_DROP_SPEED * -1) {
        movement.y = movement.y + FLAKE_DAMPING_RATE;
    } else if(movement.y > FLAKE_NORMAL_DROP_SPEED * -1) {
        movement.y = FLAKE_NORMAL_DROP_SPEED * -1;
    }
    
    // let flakes rest when reached the floor
    if (getY() < 0) {
        restingCounter++;
        
        if (restingCounter > FLAKE_LIFETIME) {
            active = false;
            return;
        }
        
        restingCounter++;
        return;
    }
    
    this->setPosition(this->getPosition() + movement + wind);

}

void Snowflake::draw() {
    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(255, 255, 255);
    
    ofVec3f pos = getPosition();
    
    ofPushMatrix();
    ofRotateY(90);
    ofTranslate(pos.x, pos.y, pos.z);
    
    ofDrawBezier(0, 0, 2.8, 0, 5, 2.2, 5, 5);
    ofDrawBezier(5, 5, 5, 7.8, 2.8, 16.4, 0, 16.4);
    ofDrawBezier(0, 16.4, -2.8, 16.4, -5, 7.7, -5, 5);
    ofDrawBezier(-5, 5, -5, 2.2, -2.8, 0, 0, 0);
    
    ofPopMatrix();
}

// PRIVATE ---------------------------------

ofVec3f Snowflake::decideStart() {
    float startX = (float)((rand() % xRange) - xRange / 2);
    float startY = yRange;
    float startZ = (float)((rand() % zRange) - zRange / 2);
    return ofVec3f(startX, startY, startZ);
}

ofVec3f Snowflake::decideMovement(float dropSpeed) {
    float targetX = (ofRandom(1) - 0.5) / 1;
    float targetY = dropSpeed * -1;
    float targetZ = (ofRandom(1) - 0.5) / 1;
    return ofVec3f(targetX, targetY, targetZ);
}
