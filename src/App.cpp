#include "App.h"

void App::setup(){
    ofBackground(0, 0, 0);
    
    mainCam.setPosition(1500, ofGetWindowWidth() / 3, 0);
    mainCam.setOrientation(ofVec3f(0, 90, 0));
    
    statehandler.snowfall = &snowfall;
    statehandler.pillow = &pillow;
    statehandler.soundscape = &soundscape;
    
    statehandler.setup();
    
    pillow.setup();
    snowfall.setup();
    soundscape.setup();
}

void App::update(){
    pillow.update();
    
    statehandler.update();
    
    snowfall.update();
    soundscape.update();
}

void App::draw(){
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
    
    // draw world
    snowfall.draw();
    
    // finish cam
    if(debug) {
        debugCam.end();
    } else {
        mainCam.end();
    }
    
    // draw info
    if(info) {
        ofSetColor(255, 255, 255);
        ofFill();
        
        ofDrawBitmapString("Forces: " + ofToString(pillow.forceLeft) + " " + ofToString(pillow.forceRight), 20, 30);
        ofDrawBitmapString("Angles: " + ofToString(pillow.angleLeft) + " " + ofToString(pillow.angleRight), 20, 50);
        ofDrawBitmapString("State: " + statehandler.debugString(), 20, 70);
        ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 20, 90);
    }
}

void App::keyPressed(int key){
    switch(key) {
        case 32: // space
            debug = !debug;
            return;
        case 'i':
            info = !info;
            return;
        case 'q':
            pillow.forceLeft += DEBUG_RATE;
            return;
        case 'a':
            pillow.forceLeft -= DEBUG_RATE;
            return;
        case 'w':
            pillow.forceRight += DEBUG_RATE;
            return;
        case 's':
            pillow.forceRight -= DEBUG_RATE;
            return;
        case 'e':
            pillow.angleLeft += DEBUG_RATE;
            return;
        case 'd':
            pillow.angleLeft -= DEBUG_RATE;
            return;
        case 'r':
            pillow.angleRight += DEBUG_RATE;
            return;
        case 'f':
            pillow.angleRight -= DEBUG_RATE;
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
