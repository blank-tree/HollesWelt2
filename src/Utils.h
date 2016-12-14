#pragma once

#include "ofMain.h"

ofColor interpolateColor(ofColor from, ofColor to, float t);

ofColor goldColor(float t);

float easeInQuart(float t, float b, float c, float d);
