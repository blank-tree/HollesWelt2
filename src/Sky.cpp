#include "Sky.h"
#include "Settings.h"

void Sky::setup() {

}

void Sky::update() {

}

void Sky::draw() {

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

    ofPushMatrix();
    ofTranslate(0,800,400); //reposition cloud #1

    //Outer
    //Stroke
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


    ofPopMatrix(); //cloud #1


//Draw cloud #2

    ofPushMatrix();
    ofTranslate(0,1200,-800); //reposition cloud #2

    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 1, 1);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape();

    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.7, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape();

    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(255);

    ofScale(1, 0.6, 0.8);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape(	);

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofCurveVertex(0, 200, 0);
    ofCurveVertex(0, 200, 200);
    ofCurveVertex(0, 0, 320);
    ofCurveVertex(0, -160, 200);
    ofCurveVertex(0, -120, 0);
    ofCurveVertex(0, -175, -300);
    ofCurveVertex(0, -25, -350);
    ofCurveVertex(0, 40, -200);
    ofEndShape();


    ofPopMatrix(); //cloud #2


//Draw cloud #3

    ofPushMatrix();
    ofTranslate(0,1300,0); //reposition cloud #3
    ofScale(1, 1.1, 1.1);

    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(255);

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

    ofPopMatrix(); //cloud #3


}
