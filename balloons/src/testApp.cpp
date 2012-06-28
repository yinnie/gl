#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
    ofBackground(0, 0, 0);	
    center = ofVec3f (ofGetWidth()/2, ofGetHeight()/2, 0);
	depth = -2000;
	ps.setup(depth);
	
    va = false;
	
	/*  lights 
	 
	//setting up the light
	glEnable(GL_LIGHTING);
    GLfloat ambientlight[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat diffuselight[] = {1.0, 0.4, 0.8, 1.0};
	GLfloat specularlight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat spotDir[] = {0,-1,-1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuselight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularlight);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);	
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);  //one global light
    
	 */
	
	glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	
	shader.load("shaders/helloWorld");
//	ofDisableArbTex();  
//	img.loadImage("grad.png");
//	ofEnableAlphaBlending();  //perhaps always good to have when using png images

}


//--------------------------------------------------------------
void testApp::draw(){
	
	glEnable(GL_DEPTH_TEST);
	
	//camera.begin();
	ofSetColor(255, 255, 0, 50);
	
	//shader.begin();
//	
//	shader.setUniform1f("time", ofGetElapsedTimef());
	
	//ofEnablePointSprites();
//    img.getTextureReference().bind();
	ps.drawVbo();  //ps.vbo.draw()?? will work?
//	img.getTextureReference().unbind();
//	ofDisablePointSprites();
//	shader.end();
	
	
	/* lights 
	
	//enable light0
	GLfloat lightPos [] = {ofGetWidth()/2, ofGetHeight()/4, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
			
	//define material:  silver
	GLfloat ambient[] = {0, 0, 0, 1.0};
	GLfloat diffuse[] = {0.5,  0.5,  0.7, 1.0};
	GLfloat specular[] = {0.7, 0.6, 0.6, 1.0}; //specular reflectance of the material
	GLfloat shininess = 32;
	
	glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	//glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//  glMateriali(GL_FRONT, GL_SHININESS, shininess);
	
	 
	*/   //end of lights
	
	//ps.draw();
//	
//	drawCeiling();
    
	//if (va) ps.drawVA();
//    else ps.drawPoints();

	
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

void testApp::drawCeiling() {
	
	glBegin(GL_QUADS);             //quads are CLOCKWISE 
	ofSetColor(225,0.5); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, depth);
		glVertex3f(ofGetWidth(), 0, depth);
		glVertex3f(ofGetWidth(), 0, 0);
		
		
	glEnd();
	
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