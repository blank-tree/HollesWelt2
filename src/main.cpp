#include "ofMain.h"

#include "App.h"

int main(){
	ofSetupOpenGL(1024, 768, OF_FULLSCREEN);

	ofRunApp(new App());
}
