#include "testApp.h"


void testApp::setup(){
	ofBackground(0);
	length = 20;   //gap of the grid
    cloth.setup(length);
	
}

void testApp::draw(){
	
	cloth.draw();
		
}

void testApp::update(){
	cloth.addforce(ofGetMouseX(), ofGetMouseY());
	cloth.update();

}

void testApp::keyPressed(int key){
	
}

void testApp::keyReleased(int key){

}

void testApp::mouseMoved(int x, int y){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){

}


void testApp::mouseReleased(int x, int y, int button){

}



