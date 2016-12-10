#include "Utils.h"

ofColor _gold = ofColor(255, 157, 0);
ofColor _white = ofColor(255, 255, 255);

ofColor interpolateColor(ofColor from, ofColor to, float t) {
    t = ofClamp(t, 0, 1);
    
    int r = (int)ofClamp(ofMap(t, 0, 1, from.r, to.r), 0, 255);
    int g = (int)ofClamp(ofMap(t, 0, 1, from.g, to.g), 0, 255);
    int b = (int)ofClamp(ofMap(t, 0, 1, from.b, to.b), 0, 255);
    
    return ofColor(r, g, b);
}

ofColor goldColor(float t) {
    return interpolateColor(_white, _gold, t);
}

float easeInQuart(float t, float b, float c, float d) {
    t /= d;
    return c*t*t*t*t + b;
}

ofPath* _cachedPath;

ofPath* snowflakePath() {
    if(_cachedPath == nil) {
        _cachedPath = new ofPath();

        _cachedPath->bezierTo(2.8, 0, 5, 2.2, 5, 5);
        _cachedPath->bezierTo(5, 7.8, 2.8, 16.4, 0, 16.4);
        _cachedPath->bezierTo(-2.8, 16.4, -5, 7.7, -5, 5);
        _cachedPath->bezierTo(-5, 2.2, -2.8, 0, 0, 0);
        _cachedPath->close();
    }

    return _cachedPath;
}
