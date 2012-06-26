#include "testApp.h"

//first a particle system of balloons

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
    ofBackground(0, 0, 0);	
    center = ofVec3f (ofGetWidth()/2, ofGetHeight()/2, 0);
	
	ps.setup();
	
    va = false;
	
	//setting up the light
	glEnable(GL_LIGHTING);
    GLfloat ambientlight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat diffuselight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat specularlight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat spotDir[] = {0,0,-1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuselight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularlight);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 100.0f);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);	
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);  //one global light
    
	glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	glEnable(GL_DEPTH_TEST);
	
	//camera.begin();
	
	//enable light0
	GLfloat lightPos [] = {ofGetWidth()/2, ofGetHeight()/2-400, -1000};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
			
	//define material:  silver
	GLfloat ambient[] = {0.19225, 0.19225, 0.19225, 1.0};
	GLfloat diffuse[] = {0.50754,  0.50754,  0.50754, 1.0};
	GLfloat specular[] = {0.508273, 0.508273, 0.508273,1.0}; //specular reflectance of the material
	GLfloat shininess = 51.2;
	
	//glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMateriali(GL_FRONT, GL_SHININESS, shininess);


	//if (va) ps.drawVA();
    //else ps.drawPoints();
	
	ps.draw();
	
	
	glDisable(GL_DEPTH_TEST);
	
    glDisable(GL_LIGHTING);
	
	//camera.end();
	
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("fps " + ofToString(ofGetFrameRate(), 2)
					   + " | useVA " + ofToString(va), 20,20);
	
}
			  
void testApp::update(){
	ps.update();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case '1':
			va = ! va;
			break;
		default:
			break;
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
	float rotateAmountX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
	float rotateAmountY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 180);
	ofVec3f furtherestPoint = ofVec3f (0, 200, -600);
	ofVec3f directionToFurtherestPoint = furtherestPoint - center;
	ofVec3f directionToFurtherestPointRotatedX = directionToFurtherestPoint.rotate(rotateAmountX, ofVec3f(0,1,0));
	ofVec3f directionToFurtherestPointRotatedY = directionToFurtherestPoint.rotate(rotateAmountY, ofVec3f(1,0,0));
	camera.setPosition(center + directionToFurtherestPointRotatedX + directionToFurtherestPointRotatedY);
	camera.lookAt(center +400);
	

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