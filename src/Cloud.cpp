#include "Cloud.h"
#include "Utils.h"

void Cloud::draw() {
    ofNoFill();
    ofSetColor(goldColor(goldness));
    ofSetLineWidth(1);
    
    ofVec3f pos = getPosition();
  
    ofPushMatrix();
    ofRotateY(90);
    ofDrawEllipse(pos.x, pos.y, pos.z, 100, 100);
    ofPopMatrix();
}
