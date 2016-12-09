#include "Sky.h"
#include "Settings.h"

void Sky::setup() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        Cloud* c = new (Cloud);
        
        c->setPosition((ofGetWindowWidth() / (CLOUD_COUNT - 1) * i) - (ofGetWindowWidth() / 2), ofGetWindowHeight(), 0);
        
        clouds[i] = c;
    }
}

void Sky::update() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        Cloud* c = clouds[i];
        
        c->goldness = goldness;
        
        ofVec3f pos = c->getPosition();
        c->setPosition(pos.x, ofMap(intensity, 0, 1, ofGetWindowHeight() + 500, ofGetWindowHeight()), pos.z);
    }
}

void Sky::draw() {
    for (int i = 0; i < CLOUD_COUNT; i++) {
        clouds[i]->draw();
    }
}

void Sky::testDraw() {

    // @Simon: Mach dini Sache do:

    /* Order the shapes are drawn:
     * - Define "NoFill" and set color to white
     * - Draw the shape once (for the border)
     * - Define "Fill" and set color to black
     * - Draw the shape a second time (for the fill)
     */



//Draw cloud #1
    //Outer
    //Stroke
    //reposition (control through input after)

    ofTranslate(0,800,0);


    ofNoFill();
    ofSetColor(255);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape();

    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(0.8, 0.75, 0.8);
    ofTranslate(0,120,100);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape();


    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.75, 0.8);
    ofTranslate(0,120,100);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofCurveVertex(0, 650, 350);
    ofCurveVertex(0, 650, 500);
    ofCurveVertex(0, 520, 620);
    ofCurveVertex(0, 500, 750);
    ofCurveVertex(0, 350, 800);
    ofCurveVertex(0, 250, 650);
    ofCurveVertex(0, 250, 100);
    ofCurveVertex(0, 450, 50);
    ofCurveVertex(0, 500, 250);
    ofEndShape();


//Draw cloud #2
    ofTranslate(0,-120,-100);

    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 1, 1);

    ofBeginShape();
    ofCurveVertex(0, -350, -600);
    ofCurveVertex(0, -50, -700);
    ofCurveVertex(0, 80, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -350, -600);
    ofCurveVertex(0, -50, -700);
    ofCurveVertex(0, 80, -400);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -350, -600);
    ofCurveVertex(0, -50, -700);
    ofCurveVertex(0, 80, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -350, -600);
    ofCurveVertex(0, -50, -700);
    ofCurveVertex(0, 80, -400);
    ofEndShape();

    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.7, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -400, -600);
    ofCurveVertex(0, -100, -700);
    ofCurveVertex(0, 80, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -400, -600);
    ofCurveVertex(0, -100, -700);
    ofCurveVertex(0, 80, -400);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -400, -600);
    ofCurveVertex(0, -100, -700);
    ofCurveVertex(0, 80, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -400, -600);
    ofCurveVertex(0, -100, -700);
    ofCurveVertex(0, 80, -400);
    ofEndShape();

    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.6, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -450, -600);
    ofCurveVertex(0, -200, -700);
    ofCurveVertex(0, 20, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -450, -600);
    ofCurveVertex(0, -200, -700);
    ofCurveVertex(0, 20, -400);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -450, -600);
    ofCurveVertex(0, -200, -700);
    ofCurveVertex(0, 20, -400);
    ofCurveVertex(0, 400, 0);
    ofCurveVertex(0, 400, 400);
    ofCurveVertex(0, 0, 640);
    ofCurveVertex(0, -320, 400);
    ofCurveVertex(0, -240, 0);
    ofCurveVertex(0, -450, -600);
    ofCurveVertex(0, -200, -700);
    ofCurveVertex(0, 20, -400);
    ofEndShape();



//Draw cloud #2

    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 4, 3);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape();

    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.7, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape();

    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.7, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofCurveVertex(0, 100, -350);
    ofCurveVertex(0, 160, -240);
    ofCurveVertex(0, 70, 50);
    ofCurveVertex(0, 100, 200);
    ofCurveVertex(0, 30, 300);
    ofCurveVertex(0, -100, 200);
    ofCurveVertex(0, -200, 0);
    ofCurveVertex(0, -100, -150);
    ofCurveVertex(0, -80, -300);
    ofEndShape();



}
