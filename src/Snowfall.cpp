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

void Snowfall::spawn() {
    Snowflake* s = activate();
    
    s->setPosition(rand() % ofGetWindowWidth(), FLAKE_START_Y, rand() % ofGetWindowWidth());
}

Snowflake* Snowfall::activate() {
    if(nextActivation >= FLAKE_COUNT) {
        nextActivation = 0;
    }
    
    Snowflake* s = flakes[nextActivation];
    s->setPosition(0, FLAKE_START_Y, 0);
    s->restingCounter = 0;
    s->startingCounter = 0;
    s->setRadius(10);
    s->setResolution(10);
    s->active = true;
    
    nextActivation++;
    
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
