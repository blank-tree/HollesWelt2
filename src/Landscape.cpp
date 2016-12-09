#include "Landscape.h"
#include "Utils.h"

void Landscape::setup() {

    intensity = 0;

    for (int i = 0; i < 3; ++i) {
        goldness[i] = 0;
    }

}

void Landscape::update() {

    goldness[0] = ofMap(intensity, 0, 0.3333, 0, 1, true);
    goldness[1] = ofMap(intensity, 0.3334, 0.6666, 0, 1, true);
    goldness[2] = ofMap(intensity, 0.6667, 1, 0, 1, true);
    
}

void Landscape::draw() {
    //RIP CODE - SO MANY LINES

    /* Order the shapes are drawn:
     * - Define "NoFill" and set color to white
     * - Draw the shape once (for the border)
     * - Define "Fill" and set color to black
     * - Draw the shape a second time (for the fill)
     */



//Draw Terrain Bottom right
    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[0]));

    ofBeginShape();
    ofCurveVertex(0, -500, -1600);
    ofCurveVertex(0, -500, -2000);
    ofCurveVertex(0, 0, -1600);
    ofCurveVertex(0, 140, -800);
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, -300, 400);
    ofCurveVertex(0, -300, 0);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -500, -1600);
    ofCurveVertex(0, -500, -2000);
    ofCurveVertex(0, 0, -1600);
    ofCurveVertex(0, 140, -800);
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, -300, 400);
    ofCurveVertex(0, -300, 0);
    ofEndShape();


    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[1]));

    ofBeginShape();
    ofCurveVertex(0, -500, -1500);
    ofCurveVertex(0, -500, -1950);
    ofCurveVertex(0, -50, -1550);
    ofCurveVertex(0, 90, -800);
    ofCurveVertex(0, -50, -50);
    ofCurveVertex(0, -300, 300);
    ofCurveVertex(0, -300, 0);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -500, -1500);
    ofCurveVertex(0, -500, -1950);
    ofCurveVertex(0, -50, -1550);
    ofCurveVertex(0, 90, -800);
    ofCurveVertex(0, -50, -50);
    ofCurveVertex(0, -300, 300);
    ofCurveVertex(0, -300, 0);
    ofEndShape();


    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[2]));

    ofBeginShape();
    ofCurveVertex(0, -500, -1400);
    ofCurveVertex(0, -500, -1900);
    ofCurveVertex(0, -100, -1500);
    ofCurveVertex(0, 40, -800);
    ofCurveVertex(0, -100, -100);
    ofCurveVertex(0, -300, 200);
    ofCurveVertex(0, -300, 0);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -500, -1400);
    ofCurveVertex(0, -500, -1900);
    ofCurveVertex(0, -100, -1500);
    ofCurveVertex(0, 40, -800);
    ofCurveVertex(0, -100, -100);
    ofCurveVertex(0, -300, 200);
    ofCurveVertex(0, -300, 0);
    ofEndShape();


//Draw Terrain Bottom left
    //Outer
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[0]));

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 2000);
    ofCurveVertex(0, -50, 1600);
    ofCurveVertex(0, 40, 1000);
    ofCurveVertex(0, -80, 400);
    ofCurveVertex(0, -300, 0);
    ofCurveVertex(0, -300, 400);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 2000);
    ofCurveVertex(0, -50, 1600);
    ofCurveVertex(0, 40, 1000);
    ofCurveVertex(0, -80, 400);
    ofCurveVertex(0, -300, 0);
    ofCurveVertex(0, -300, 400);
    ofEndShape();

    //Middle
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[1]));

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 1900);
    ofCurveVertex(0, -90, 1550);
    ofCurveVertex(0, -20, 1000);
    ofCurveVertex(0, -105, 480);
    ofCurveVertex(0, -300, 100);
    ofCurveVertex(0, -300, 500);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 1900);
    ofCurveVertex(0, -90, 1550);
    ofCurveVertex(0, -20, 1000);
    ofCurveVertex(0, -105, 480);
    ofCurveVertex(0, -300, 100);
    ofCurveVertex(0, -300, 500);
    ofEndShape();

    //Inner
    //Stroke
    ofNoFill();
    ofSetColor(goldColor(goldness[2]));

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 1850);
    ofCurveVertex(0, -125, 1480);
    ofCurveVertex(0, -80, 990);
    ofCurveVertex(0, -155, 530);
    ofCurveVertex(0, -300, 200);
    ofCurveVertex(0, -300, 600);
    ofEndShape();

    //Fill
    ofFill();
    ofSetColor(0);

    ofBeginShape();
    ofCurveVertex(0, -300, 1600);
    ofCurveVertex(0, -300, 1850);
    ofCurveVertex(0, -125, 1480);
    ofCurveVertex(0, -80, 990);
    ofCurveVertex(0, -155, 530);
    ofCurveVertex(0, -300, 200);
    ofCurveVertex(0, -300, 600);
    ofEndShape();
}
