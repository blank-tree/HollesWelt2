#include "Landscape.h"

void Landscape::setup() {
    
    for (int i = 0; i < LAND_COUNT; i++) {
        land[i] = new (Plane);
    }
}

Plane* Landscape::spawn() {
    if(next >= LAND_COUNT) {
        next = 0;
    }
    
    Plane* p = land[next];
    p->setup();
    
    next++;
    
    return p;
}

void Landscape::update() {
    
    for (int i = 0; i < LAND_COUNT; i++) {
        Plane* p = land[i];
        
        p->update();
    }
    
}

void Landscape::draw() {
    for (int i = 0; i < LAND_COUNT; i++) {
        Plane* p = land[i];
        
        if(!p->active) {
            continue;
        }
        
        ofSetColor(p->color);
        ofNoFill();
        
        p->draw();
    }
}

void Landscape::colorGold(int amount) {
    for (int i = 0; i < LAND_COUNT; i++) {
        Plane* p = land[i];
        
        if (!p->active) {
            continue;
        }
        
        p->fade(i < amount);
    }
}

void Landscape::testDraw() {

    // @Simon: Mach dini Sache do:




}

