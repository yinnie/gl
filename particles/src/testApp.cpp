#include "testApp.h"

//working towards a field of grass...
//first a particle system of points

//--------------------------------------------------------------
void testApp::setup(){
	
	//ofSetVerticalSync(TRUE);
	
	ofBackground(0, 0, 0);	
    
	ps.setup();
	ofDisableArbTex();  //dont forget this when applying 2D texture!!
	img.loadImage("grad.png");
	va = false;
}


//--------------------------------------------------------------
void testApp::draw(){
	
	glEnable(GL_DEPTH_TEST);
	//img.getTextureReference().bind();
	
	if (va) ps.drawVA();
	else ps.drawPoints();
	
	img.getTextureReference().unbind();
	glDisable(GL_DEPTH_TEST);
	
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