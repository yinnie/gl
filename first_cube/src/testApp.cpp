#include "testApp.h"

//making first rotating box in OF. 
//--------------------------------------------------------------
void testApp::setup(){
	

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	rotation = 0;
	bDrawWireframe = false;
	center.set(ofGetWidth()/2, ofGetHeight()/2, 0); 
	radius = 300;
    depth = -500;
    
	shader.load("shaders/distort.vs", "shaders/distort.fs");

}


//--------------------------------------------------------------
void testApp::draw(){
	
	
	
//	if(bDrawWireframe) ofNoFill();
//	else ofFill();
//	
	ofSetColor(255,0,0);
	
	shader.begin();
	
	/*
	//we want to pass in some varrying values to animate our type / color 
	shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
	shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
	
	//we also pass in the mouse position 
	//we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped. 
	shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
	*/
	
	shader.setUniform3f("lightPosition", 400, 300, -500);
	shader.setUniform3f("BrickColor", 255, 0, 0);
	shader.setUniform3f("MortarColor", 0, 255, 0);
	shader.setUniform2f("BrickSize", 0.3, 0.15);
	shader.setUniform2f("BrickPct", 0.9, 0.85);

	
	//ofPushMatrix();
//    glColor3f(255, 0, 0);
//	ofTranslate(center.x, center.y, center.z);
//	ofRotate(rotation, 0, 0, 1);
//	float x = cos(angle)*radius;
//	float y = sin(angle)*radius;
	
	ofBox(500, 500, -200, 200); 
	ofSphere(200, 200, -200, 200); 
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