#include "Snowflake.h"
#include "Settings.h"
#include "Utils.h"

void drawSnowflake(ofColor color) {
    // use a static path that can be reused
    static ofPath* path;

    // create path if missing
    if(path == nil) {
        path = new ofPath();
        path->setFilled(false);
        path->setStrokeWidth(1.5);

        path->bezierTo(2.8, 0, 5, 2.2, 5, 5);
        path->bezierTo(5, 7.8, 2.8, 16.4, 0, 16.4);
        path->bezierTo(-2.8, 16.4, -5, 7.7, -5, 5);
        path->bezierTo(-5, 2.2, -2.8, 0, 0, 0);
        path->close();
    }

    // set color and draw path
    path->setColor(color);
    path->draw();
}

void Snowflake::setup(float dropSpeed, float goldness) {
    // set active
    active = true;

    // set goldness
    this->goldness = goldness;

    // enforce min drop speed
    if(dropSpeed < FLAKE_MIN_DROP_SPEED) {
        dropSpeed = FLAKE_MIN_DROP_SPEED;
    }

    // define range
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
    float targetY = dropSpeed * -1;
    float targetZ = (float)(ofRandom(1) - 0.5);
    movement = ofVec3f(targetX, targetY, targetZ);

    // calculate dead point
    endY = -300 + this->getZ() / 2;
}

void Snowflake::update(ofVec3f wind) {
    // skip inactive flakes
    if(!active) {
        return;
    }

    // slow down movement
    if(movement.y + FLAKE_DAMPING_RATE < FLAKE_MIN_DROP_SPEED * -1) {
        movement.y += FLAKE_DAMPING_RATE;
    }

    // deactivate snowflakes when reached the endY point
    if (getY() < this->endY) {
        active = false;
        return;
    }

    // move flake and apply global wind
    this->setPosition(this->getPosition() + movement + wind);
}

void Snowflake::draw() {
    // skip inactive flakes
    if(!active) {
        return;
    }

    // prepare matrix
    ofPushMatrix();
    ofRotateY(90);
    ofTranslate(getX(), getY(), getZ());

    // draw snowflake
    drawSnowflake(goldColor(goldness));

    // finish matrix
    ofPopMatrix();
}

void Snowflake::reset() {
    active = false;
}
