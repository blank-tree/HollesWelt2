#include "ofMain.h"

#include "App.h"

int main(){
	ofSetupOpenGL(1920, 1080, OF_WINDOW);

	ofRunApp(new App());
}
