#include "testApp.h"

//making first rotating box in OF. 
//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
	ofBackground(0, 0, 0);	
	rotation = 0;
	bDrawWireframe = false;
	center.set(ofGetWidth()/2, ofGetHeight()/2, 0); 
	radius = 300;
    depth = -500;
    
	shader.load("shaders/helloWorld");

}


//--------------------------------------------------------------
void testApp::draw(){
	
	if(bDrawWireframe) ofNoFill();
	else ofFill();
	
	shader.begin();
	
	//ofPushMatrix();
//    glColor3f(255, 0, 0);
//	ofTranslate(center.x, center.y, center.z);
//	ofRotate(rotation, 0, 0, 1);
//	float x = cos(angle)*radius;
//	float y = sin(angle)*radius;
	//ofBox(0, 0, 0, 100);
	glutSolidTeapot(130);
	/*
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, depth);
	glVertex3f(ofGetWidth(), 0, depth);
	glVertex3f(ofGetWidth(), 0, 0);
	*/
	
	glEnd();
	

	//ofPopMatrix();
	
	shader.end();
	

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