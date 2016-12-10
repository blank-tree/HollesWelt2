#pragma once

#include "ofMain.h"

ofColor interpolateColor(ofColor from, ofColor to, float t);

ofColor goldColor(float t);

// http://gizma.com/easing/#quad1
// http://easings.net
float easeInQuart(float t, float b, float c, float d);

ofPath* snowflakePath();
