#include "testApp.h"


testApp::testApp()   
:cloth(50,50,5)
{    //intilizer list has to have a body even if it is empty
} 

void testApp::setup() {
    ofSetVerticalSync(true);
	ofBackground(0);
	pull = ofVec3f(0,0,0);
	preMouseX = 0;
	preMouseY = 0;
	//cloth = Cloth(50,50,5);    //cannot initialise like this..this is more like 'assignment'. 
								 //cloth does not have default constructor of its own. 

}

void testApp::update() {

	cloth.update(); 
}

void testApp:: draw() {
	cloth.draw();
}
	
void testApp:: mouseDragged(int x, int y, int Button){
    
	
	ofVec3f mousePos = ofVec3f (ofGetMouseX(), ofGetMouseY(),0);
	ofVec3f dragDirection = mousePos - ofVec3f(preMouseX, preMouseY,0);
	pull = dragDirection;   //simplified here...should normalized and use distances..
	cout << pull << endl;
	
	for (int i = 0; i<cloth.particles.size(); i++) {
		bool inside = cloth.particles[i].insideMouseForce(preMouseX, preMouseY);
		if (inside) {
			cloth.particles[i].applyForce(pull);
		}
	}	
   
	preMouseX = x;  //these must be at the end!! 
	preMouseY = y;
}
		
void testApp:: keyPressed(int key) {
	cloth.reset();
}
		
	
	
	
	
	
	
	
