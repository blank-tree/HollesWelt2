#include "Snowflake.h"
#include "Settings.h"
#include "Utils.h"

void Snowflake::setup(float dropSpeed, float goldness) {
    this->goldness = goldness;
    
    active = true;

    // set range
    int xRange = ofGetWindowWidth() * 2;
    int yRange = (int)(ofGetWindowHeight() * 1.1);
    int zRange = 1000;

    // calculate position
    float startX = (float)((rand() % xRange) - xRange / 2);
    float startZ = (float)((rand() % zRange) - zRange / 2);
    float startY = yRange + 450 - startZ / 2;
    this->setPosition(ofVec3f(startX, startY, startZ));

    // calculate movement
    float targetX = (float)(ofRandom(1) - 0.5);
    float targetY = (float)(dropSpeed * -1 < -FLAKE_NORMAL_DROP_SPEED ? dropSpeed * -1 : -FLAKE_NORMAL_DROP_SPEED);
    float targetZ = (float)(ofRandom(1) - 0.5);
    movement = ofVec3f(targetX, targetY, targetZ);

    // calculate dead point
    endY = -300 + this->getZ() / 2;
    
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

    // deactivate snowflakes when reached the endY point
    if (getY() < this->endY) {
        active = false;
        return;
    }
    
    this->setPosition(this->getPosition() + movement + wind);
}

void Snowflake::draw() {
    if(!active) {
        return;
    }
    
    ofColor c = goldColor(goldness);

    ofPath* path = snowflakePath();
    path->setColor(c);
    
    ofVec3f pos = getPosition();
    
    ofPushMatrix();
    ofRotateY(90);
    ofTranslate(pos.x, pos.y, pos.z);

    path->draw();
    
    ofPopMatrix();
}

void Snowflake::reset() {
    active = false;
}
