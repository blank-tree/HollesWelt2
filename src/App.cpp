#include "App.h"

void App::setup(){
    ofBackground(0, 0, 0);
    
    mainCam.setPosition(1500, ofGetWindowWidth() / 2, 0);
    mainCam.setOrientation(ofVec3f(0, 90, 0));
    
    snowfall.setup();
}

void App::update(){
    snowfall.spawn();
    snowfall.update();
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
