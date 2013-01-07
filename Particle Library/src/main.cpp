
//© Kolten Robison 2012-2013

#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
	ofSetupOpenGL(&window, 1024, 768, OF_FULLSCREEN);
	ofRunApp(new testApp()); // start the app
}
