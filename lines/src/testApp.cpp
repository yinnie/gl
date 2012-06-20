#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	glEnable(GL_DEPTH_TEST);
	
	ofBackground(0, 0, 0);	
    //cam.setDistance(0);	
	//cam.enableMouseInput();
    
}


//--------------------------------------------------------------
void testApp::draw(){

	z = -50;  //to draw a static shape, initialise z in draw(),not setup()
	//cam.begin();
	glEnable(GL_LINE_STIPPLE);  //making dotted lines
	GLint factor = 5;   //factor determines how 'big' the stipple is
	GLushort pattern = 0x5555;
	glLineStipple(factor, pattern);
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

    for (double angle = 0.00; angle < 2.00*PI; angle += 2.00*PI/20) 
	{   
		
		x = 150*cos(angle);
		y = 150*sin(angle);
		
		glBegin(GL_LINES);       //only include after glBegin() the primitives you draw.
		  glColor3f(0, 1.0f, 0);  //Have to use glColor inside of glBegin()
		  glVertex3f(0, 0, 0);
		  glVertex3f(x, y, z);
		glEnd();
		
		//z += 0.65; //if want z changes to be part of the shape, put z increment inside for() loop

	}
	
	glPopMatrix();
	
	//cam.end();
}

void testApp::update(){
   
	
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