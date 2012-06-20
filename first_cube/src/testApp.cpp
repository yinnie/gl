#include "testApp.h"

//making first rotating box in OF. 
//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofBackground(0, 0, 0);	
	rotation = 0;
	bDrawWireframe = false;
	radius = 300;
	center.set(ofGetWidth()/2, ofGetHeight()/2, 0); 
	angle = TWO_PI/8;
}


//--------------------------------------------------------------
void testApp::draw(){
	
	if(bDrawWireframe) ofNoFill();
	else ofFill();
	
	ofPushMatrix();
	ofSetColor(255,255,0);
	ofTranslate(center.x, center.y, center.z);
	ofRotate(rotation, 0, 0, 1);
	float x = cos(angle)*radius;
	float y = sin(angle)*radius;
	ofBox(x, y, 0, 100);
	ofPopMatrix();
	
	
}

void testApp::debugDraw() {
	
}

//--------------------------------------------------------------
void testApp::update(){
     rotation += 1;
	if (rotation >= 360) rotation = 0; //this is so the cube reverse direction
	//angle +=0.05;

	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	bDrawWireframe = !bDrawWireframe;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}