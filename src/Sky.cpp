#include "Sky.h"
#include "Settings.h"

void Sky::setup() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        Cloud* c = new (Cloud);
        
        c->setPosition((ofGetWindowWidth() / (CLOUD_COUNT - 1) * i) - (ofGetWindowWidth() / 2), ofGetWindowHeight(), 0);
        
        clouds[i] = c;
    }
}

void Sky::update() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        Cloud* c = clouds[i];
        
        ofVec3f pos = c->getPosition();
        c->setPosition(pos.x, ofMap(intensity, 0, 1, ofGetWindowHeight() + 400, ofGetWindowHeight()), pos.z);
    }
}

void Sky::draw() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        clouds[i]->draw();
    }
}
