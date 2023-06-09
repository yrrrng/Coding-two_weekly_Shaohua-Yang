#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0,0,0);

	// try to grab at this size
	camWidth = 640;
	camHeight = 480;
	
	vidGrabber.setVerbose(true);
	vidGrabber.setup(camWidth,camHeight);

	//font.load("Courier New Bold.ttf", 9);
	
	// this set of characters comes from the Ascii Video Processing example by Ben Fry,
	// changed order slightly to work better for mapping
	//asciiCharacters =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
	
	ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // change background video alpha value based on the cursor's x-position
    float threshold = ofMap(mouseX, 0, ofGetWidth(), 0, 255, false);
    
    int r = ofMap(mouseY, 0, ofGetHeight(), 0, 255, true);
    int g = ofMap(mouseY, 0, ofGetHeight(), 0, 0, true);
    int b = ofMap(mouseY, 0, ofGetHeight(), 0, 0, true);

    // set a white fill color with the alpha generated above
    ofSetColor(255,255,255,threshold);
    
    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);
    
    ofPixelsRef pixelsRef = vidGrabber.getPixels();
    
    //ofSetHexColor(0xf00fff);
    
    
    for (int i = 0; i < camWidth; i += 2) {
        for (int j = 0; j < camHeight; j += 2) {
            // get the pixel and its lightness (lightness is the average of its RGB values)
            float lightness = pixelsRef.getColor(i, j).getLightness();
            
            // check if the lightness is above the threshold
            if (lightness > threshold) {
                // set color to random and draw a rectangle
                ofSetColor(r-1, g, b);
                ofDrawRectangle(i, j, 2, 2);
            } else {
                // set color to black and draw a rectangle
                ofSetColor(ofRandom(0),ofRandom(255),ofRandom(0));
                ofDrawRectangle(i, j, 2, 2);
            }
        }
    }
}
    
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...
	
	if (key == 's' || key == 'S'){
		vidGrabber.videoSettings();
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
