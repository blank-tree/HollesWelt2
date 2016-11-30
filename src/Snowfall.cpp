//
//  Snowing.cpp
//  HollesWelt
//
//  Created by Fernando Obieta on 29.11.16.
//
//

#include "Snowfall.h"

void Snowfall::setup() {
    for(int i=0; i<FLAKE_COUNT; i++) {
        flakes[i] = new(Snowflake);
    }
}

Snowflake* Snowfall::spawn() {
    if(next >= FLAKE_COUNT) {
        next = 0;
    }
    
    float x = (rand() % ofGetWindowWidth()) - (ofGetWindowWidth() / 2);
    float z = (rand() % ofGetWindowWidth()) - (ofGetWindowWidth() / 2);
    
    Snowflake* s = flakes[next];
    s->setPosition(x, FLAKE_START_Y, z);
    s->restingCounter = 0;
    s->startingCounter = 0;
    s->setRadius(10);
    s->setResolution(10);
    s->active = true;
    
    next++;
    
    return s;
}

void Snowfall::update() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        Snowflake* s = flakes[i];
        
        if(!s->active) {
            continue;
        }
        
        if (s->getY() < 0) {
            s->restingCounter++;
            
            if (s->restingCounter > FLAKE_LIFETIME) {
                s->active = false;
                continue;
            }
            
            s->restingCounter++;
            continue;
        }
        
        s->setPosition(s->getX(), s->getY() - 10, s->getZ());
    }
}

void Snowfall::draw() {
    for(int i = 0; i < FLAKE_COUNT; i++) {
        Snowflake* s = flakes[i];
        
        if(!s->active) {
            continue;
        }
        
        int grey = 255;
        
        if (s->restingCounter > 0) {
            grey = ofMap(s->restingCounter, 0, FLAKE_LIFETIME, 255, 0);
        }
        
        ofSetColor(grey, grey, grey);
        ofFill();
        
        s->draw();
    }
}
