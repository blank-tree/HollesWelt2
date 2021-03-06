#pragma once

#include "ofMain.h"

#include "Statehandler.h"
#include "Pillow.h"
#include "Snowfall.h"
#include "Soundscape.h"

class App : public ofBaseApp{
	public:
        bool debug = false;
        bool info = false;
    
        ofEasyCam debugCam;
        ofCamera mainCam;
    
        Statehandler statehandler;
    
        Pillow pillow;
        Snowfall snowfall;
        Soundscape soundscape;
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
