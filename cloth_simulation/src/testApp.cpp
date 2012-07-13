#include "testApp.h"


testApp::testApp()    //initializer list 
:cloth(10,10,10){}

void testApp::setup() {
	ofBackground(150);
}

void testApp::update() {
	cloth.applyForce(pull);
	cloth.applySprings();
}

void testApp:: draw() {
	cloth.draw();
}
	
void testApp:: mouseDragged(int x, int y, int Button){
	ofVec3f mousePosition = ofVec3f (ofGetMouseX(), ofGetMouseY(), 0);
	ofVec3f dragDirection = mousePosition - cloth.center;
	pull = dragDirection * 0.1;   //simplified here...should normalized and use distances..
}
		
		
		
	
	
	
	
	
	
	
