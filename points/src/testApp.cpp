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
	GLfloat sizes[2];
	GLfloat step;
	GLfloat curSize;
	z = -50;  //to draw a static shape, initialise z in draw(),not setup()
	//cam.begin();
    glGetFloatv(GL_POINT_SIZE_RANGE, sizes);       //sizes is already a pointer becoz it is an array
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); //*params means that at this spot you need a pointer
	                                               //* is the dereference operator..usu used to declare a variable of pointer type
	curSize = sizes[0];
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	//ofTranslate(-300, -50, 0); //?? once I use translate here, ofRotate is messed up
	ofRotateX(5);
	ofRotateY(20);
	glBegin(GL_LINE_STRIP);      //call line_strip to connect all the points
    for (double angle = 0.00; angle < 2.00*PI*4; angle += 0.035) 
	{   
		
		glPointSize(curSize);     //glPointSize() needs to stay out of glBegin
		x = 60*cos(angle);
		y = 60*sin(angle);
		
		//glBegin(GL_POINTS);       //only include after glBegin() the primitives you draw.
		  glColor3f(1.0f, 0, 0);  //Have to use glColor inside of glBegin()
		  glVertex3f(x, y, z);
		//glEnd();
		
		z += 0.65; //if want z changes to be part of the shape, put z increment inside for() loop
	    curSize += step*0.3;
	}
	
	
	glEnd();
	
	
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