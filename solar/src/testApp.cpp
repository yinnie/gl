#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	glEnable(GL_DEPTH_TEST);
	rotaE = 0.0;
	rotaM = 0;

	ofBackground(0, 0, 0);	
      
}


//--------------------------------------------------------------
void testApp::draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	ofPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -200.0f);
	//ofTranslate(ofGetWidth()/2, ofGetHeight()/2, -200);
	
	//the sun 
	ofSetColor(255,255,0);
	ofSphere(0, 0, 0, 15);

	
	//the earth
	glRotatef(rotaE, 0, 1.0f, 0);
	ofSetColor(255);
	glTranslatef(100, 0, 0);          // this moves the coordinate system to move the earth some distance from the sun..
	                                  //use Translate, dont put 100 in the ofSphere(x, y, z,10) below..becoz then the moon will not be circling the earth
	ofSphere(0, 0, 0, 10);
	
	//the moon
	glRotatef(rotaM, 0, 1.0f, 0);
	ofSetColor(255,0,255);
	glTranslatef(60, 0, 0);
	ofSphere(0, 0, 0, 6);
	
	ofPopMatrix();

}

void testApp::update(){
	rotaE += 0.3;
	rotaM += 1;
	if (rotaE > 360) {
		rotaE = 0;
	}
	if (rotaM > 360) {
		rotaM = 0;
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	
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