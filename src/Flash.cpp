//
//  Flash.cpp
//  HollesWelt
//
//  Created by Joël Gähwiler on 01.12.16.
//
//

#include "Flash.h"

void Flash::draw() {
    ofFill();
    ofSetColor(255, 157, 0, intensity * 255);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}
