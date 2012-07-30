#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(34, 34, 34);
	ofEnableAlphaBlending();
    //cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	
	shader.load("shaders/normal.vs", "shaders/normal.fs");
	//shader.load("shaders/perFragLight.vs", "shaders/perFragLight.fs");
	
	//ofDisableArbTex();
	//img.loadImage("grad.png");
	
	/*//cubemap
	cubeMap.loadImages("cubePosX.jpg",
					   "cubePosY.jpg",
					   "cubePosZ.jpg",
					   "cubeNegX.jpg",
					   "cubeNegY.jpg",
					   "cubeNegZ.jpg");
	cubeMap.enableFixedMapping();  */

}


void testApp::draw(){
	
	ofSetColor(0,150,0);
	//glEnable(GL_TEXTURE_CUBE_MAP);
	//glEnable(GL_DEPTH_TEST);
	
	//cam.begin();
	shader.begin();
	
	/*//cubeMap
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap.textureObject);
	shader.setUniform1i("cubeMap", 0);  */
	
	shader.setUniform3f("lightPosition", 60, 20, 200);
	
	//shader.setUniformTexture("tex", img, 1);
	shader.setUniform1f("time", ofGetElapsedTimef());
//	shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
//	shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
//	shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
//	
//	shader.setUniform3f("BrickColor", 255, 0, 0);	
//	shader.setUniform3f("MortarColor", 0, 255, 0);
//	shader.setUniform2f("BrickSize", 0.3, 0.15);
//	shader.setUniform2f("BrickPct", 0.9, 0.85);
    
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    //roate??
	ofSphere(0, 0, 0, 40); 
	
	//shader.setUniform1f("time", (ofGetElapsedTimef()+500));
	//ofBox(0, 100, -100, 100);
	
	
	shader.end();
	
    cam.end();
}

void testApp::update(){

}

