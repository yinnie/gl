#include "testApp.h"


testApp::testApp()    //initializer list 
:cloth(30,30,20){}

void testApp::setup() {

	ofBackground(0);
	pull = ofVec3f(0,0,0);
	center = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0);
	mouseDrag = false;
}

void testApp::update() {
	cloth.applyForce(pull);
	if(mouseDrag) cloth.update();
}

void testApp:: draw() {
	cloth.draw();
}
	
void testApp:: mouseDragged(int x, int y, int Button){
	mouseDrag = true;
	ofVec3f mousePosition = ofVec3f (ofGetMouseX(), ofGetMouseY(), 0);
	ofVec3f dragDirection = mousePosition - center;
	pull = dragDirection*0.001;   //simplified here...should normalized and use distances..
}
		
void testApp:: keyPressed(int key) {
	cloth.reset();
}
		
	
	
	
	
	
	
	
