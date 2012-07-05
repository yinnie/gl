#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
    ofBackground(0, 0, 0);	
    center = ofVec3f (ofGetWidth()/2, ofGetHeight()/2, 0);
	depth = -1000;
	ps.setup(depth);
	
    drawVa = false;
	drawVao = false;
	drawPoints = false;
	useShader = true;
	
	glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	ofDisableArbTex();  
	img.loadImage("grad.png");
	ofEnableAlphaBlending();  
	
	
	if (drawVao) {    //IN PROGRESS
		//since we want to bind data to attribute index, which has to be done before linkProgram, we setup shaders manually
		//in progress
		shader.setupShaderFromFile(GL_VERTEX_SHADER, "balloon");   
		shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "balloon");
		//glBindAttribLocation(shader, 0, "in_position");
		//glBindAttribLocation(shader, 1, "in_color");
		shader.linkProgram();		
	}
	
	shader.load("shaders/perFragLight.vs", "shaders/perFragLight.fs");	
			
}


//--------------------------------------------------------------
void testApp::draw(){
	
	glEnable(GL_DEPTH_TEST);
	
	//camera.begin();

	//ofEnablePointSprites();
	
	//ofSetColor(250, 167, 43, 255);
	if(useShader) {
		shader.begin();
		
	    
		shader.setUniform1f("time", ofGetElapsedTimef());
		
		shader.setUniformTexture("tex0", img, 1);
		
		shader.setUniform3f("lightPosition", 600, 300, -400);
		shader.setUniform3f("BrickColor", 255, 0, 0);
		shader.setUniform3f("MortarColor", 0, 0, 0);
		shader.setUniform2f("BrickSize", 0.3, 0.15);
		shader.setUniform2f("BrickPct", 0.9, 0.85);
	}
	
	if (drawVao) { ps.drawVao(); }    //ps.vbo.draw()?? will work?
	else if (drawVa) {ps.drawVA(); }
		else if (drawPoints) { ps.drawPoints(); } 
		else {
			ps.draw();}
		
	if (useShader) shader.end();

	//drawCeiling();
	
	//camera.end();

	ofSetColor(255, 255, 255);
	ofDrawBitmapString("fps " + ofToString(ofGetFrameRate(), 2)
					   + " | useVA " + ofToString(drawVa), 20,20);	
}
			  
void testApp::update(){
	ps.update();
	
}

void testApp::drawCeiling() {
	

	glDisable(GL_CULL_FACE);
	ofMesh mesh;

	mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	
	mesh.addColor(ofColor(255,255,255));
	AddFace(mesh, ofVec3f(0, 0, 0), ofVec3f(0, 0, depth),  ofVec3f(ofGetWidth(), 0, depth),  ofVec3f(ofGetWidth(), 0, 0));
	
	/*
	mesh.addVertex (ofVec3f(0, 0, 0));
	mesh.addVertex (ofVec3f(0, 0, depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, 0));
	*/
	mesh.draw();
	glEnable(GL_CULL_FACE);

}

void testApp::AddFace (ofMesh &mesh, ofVec3f a, ofVec3f b, ofVec3f c) {
	mesh.addVertex(a);
	mesh.addVertex(b);
	mesh.addVertex(c);
}

void testApp::AddFace (ofMesh &mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
	AddFace(mesh, a, b, c);
	AddFace(mesh, a, c, d);
	AddFace(mesh, a, b, d);
	AddFace(mesh, b, c, d);

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case '1':
			drawVa= ! drawVa;
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