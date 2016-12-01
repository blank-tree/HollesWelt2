//
//  Utils.cpp
//  HollesWelt
//
//  Created by Joël Gähwiler on 01.12.16.
//
//

#include "Utils.h"

ofColor _gold = ofColor(255, 157, 0);
ofColor _white = ofColor(255, 255, 255);

ofColor interpolateColor(ofColor from, ofColor to, float t) {
    t = ofClamp(t, 0, 1);
    
    int r = (int)ofClamp(ofMap(t, 0, 1, from.r, to.r), 0, 255);
    int g = (int)ofClamp(ofMap(t, 0, 1, from.g, to.g), 0, 255);
    int b = (int)ofClamp(ofMap(t, 0, 1, from.b, to.b), 0, 255);
    
    return ofColor(r, g, b);
}

ofColor goldColor(float t) {
    return interpolateColor(_white, _gold, t);
}
