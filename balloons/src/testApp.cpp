#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
    ofBackground(0, 0, 0);	
    depth = -600;
	center = ofVec3f (ofGetWidth()/2, ofGetHeight()/2, depth/2);
	ps.setup(depth);
	
    drawVa = false;
	drawVao = false;
	drawPoints = false;
	useShader = true;
	goBalloon = false;
	goSpring = true;
	
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
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//camera.begin();

	//ofEnablePointSprites();	
	
	if(useShader) {
		shader.begin();
				
		shader.setUniform1f("time", ofGetElapsedTimef());
		
		shader.setUniformTexture("tex0", img, 1);
		
		shader.setUniform3f("lightPosition", ofGetWidth()/2, ofGetHeight()/2, depth/2);
//		shader.setUniform3f("BrickColor", 255, 0, 0);
//		shader.setUniform3f("MortarColor", 0, 0, 0);
//		shader.setUniform2f("BrickSize", 0.3, 0.15);
//		shader.setUniform2f("BrickPct", 0.9, 0.85);
	}
	
	if (drawVao) { ps.drawVao(); }    //ps.vbo.draw()?? will work?
	else if (drawVa) {ps.drawVA(); }
		else if (drawPoints) { ps.drawPoints(); } 
		else {
			ps.draw();}
		
    shader.end();
    
	ofSetColor(0);
	ofSetLineWidth(5);
	ofLine(0, ofGetHeight(), 0, 0, ofGetHeight(),depth);
	ofLine(0, 0, depth, 0, ofGetHeight(),depth);
	ofLine(0, ofGetHeight(), depth, ofGetWidth(), ofGetHeight(),depth);
	ofLine(ofGetWidth(), 0, depth, ofGetWidth(), ofGetHeight(),depth);
	ofLine(ofGetWidth(), ofGetHeight(), depth, ofGetWidth(), ofGetHeight(),0);
	
	ofSetColor(255, 255, 255);
	drawCeiling();
	
	ofSetColor(150);
	drawRoom();
		
	glEnable(GL_CULL_FACE);
	
	//camera.end();

	ofDrawBitmapString("fps " + ofToString(ofGetFrameRate(), 2)
					   + " | useVA " + ofToString(drawVa), 20,20);	
}
			  
void testApp::update(){
	
	if(goBalloon) ps.update();

	if (goSpring) ps.updateSpring(depth, center);
	
	ps.checkBoundary(depth);
	
}

void testApp::drawCeiling() {
	
	glDisable(GL_CULL_FACE);
	ofMesh mesh;
	ofVbo vbo; 
	
	mesh.addVertex (ofVec3f(0, 0, 0));
	mesh.addVertex (ofVec3f(0, 0, depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, 0));
	
    vbo.setMesh(mesh, GL_STATIC_DRAW);
	vbo.draw(GL_QUADS, 0, 4);	
}

void testApp:: drawRoom() {
	glDisable(GL_CULL_FACE);
	ofMesh mesh;
	ofVbo vbo; 
	
	//floor
	mesh.addVertex (ofVec3f(0, ofGetHeight(), 0));
	mesh.addVertex (ofVec3f(0, ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), ofGetHeight(), 0));
	//right wall
	mesh.addVertex (ofVec3f(ofGetWidth(), ofGetHeight(), 0));
	mesh.addVertex (ofVec3f(ofGetWidth(), ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, 0));
	//left wall

	mesh.addVertex (ofVec3f(0, ofGetHeight(), 0));
	mesh.addVertex (ofVec3f(0, ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(0, 0, depth));
	mesh.addVertex (ofVec3f(0, 0, 0));
    //back wall	

	mesh.addVertex (ofVec3f(0, ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), ofGetHeight(), depth));
	mesh.addVertex (ofVec3f(ofGetWidth(), 0, depth));
	mesh.addVertex (ofVec3f(0, 0, depth));
	
    vbo.setMesh(mesh, GL_STATIC_DRAW);
	vbo.draw(GL_QUADS, 0, 16);	
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
	goBalloon = true;	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
	//camera movement
	float rotateAmountX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
	float rotateAmountY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 180);
	ofVec3f furtherestPoint = ofVec3f (0, 300, depth);
	ofVec3f directionToFurtherestPoint = furtherestPoint - center;
	ofVec3f directionToFurtherestPointRotatedX = directionToFurtherestPoint.rotate(rotateAmountX, ofVec3f(0,1,0));
	ofVec3f directionToFurtherestPointRotatedY = directionToFurtherestPoint.rotate(rotateAmountY, ofVec3f(1,0,0));
	camera.setPosition(center + directionToFurtherestPointRotatedX + directionToFurtherestPointRotatedY);
	camera.lookAt(center);	
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
		ps.mouseIsMoved = true;
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	ps.dragged = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    ps.dragged = false;
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