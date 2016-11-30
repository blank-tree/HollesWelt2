#include "App.h"

void App::setup(){
    ofBackground(0, 0, 0);
    
    mainCam.setPosition(1500, ofGetWindowWidth() / 2, 0);
    mainCam.setOrientation(ofVec3f(0, 90, 0));
    
    pillow.setup();
    snowfall.setup();
    
    wind = ofVec3f(0, 0, 0);
}

void App::update(){
    snowfall.spawn();
    
    // TODO: Caluclate wind;
    
    pillow.update();
    snowfall.update(wind);
}

void App::draw(){
    // draw 2d debug info
    if(debug) {
        ofDrawBitmapString("Forces: " + ofToString(pillow.forceLeft) + " " + ofToString(pillow.forceRight), 20, 30);
        ofDrawBitmapString("Angles: " + ofToString(pillow.angleLeft) + " " + ofToString(pillow.angleRight), 20, 50);
    }
    
    // begin camera
    if(debug) {
        debugCam.begin();
    } else {
        mainCam.begin();
    }
    
    // draw debug info
    if(debug) {
        ofDrawAxis(100);
    
        mainCam.draw();
    }
    
    // draw snowfall
    snowfall.draw();
    
    // finish cam
    if(debug) {
        debugCam.end();
    } else {
        mainCam.end();
    }
}

void App::keyPressed(int key){
    if(key == 'd') {
        debug = !debug;
        return;
    }
}

void App::keyReleased(int key){}

void App::mouseMoved(int x, int y ){}

void App::mouseDragged(int x, int y, int button){}

void App::mousePressed(int x, int y, int button){}

void App::mouseReleased(int x, int y, int button){}

void App::mouseEntered(int x, int y){}

void App::mouseExited(int x, int y){}

void App::windowResized(int w, int h){}

void App::gotMessage(ofMessage msg){}

void App::dragEvent(ofDragInfo dragInfo){}
