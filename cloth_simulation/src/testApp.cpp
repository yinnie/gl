#include "testApp.h" 

testApp::testApp() 
: cloth(50,50,5) {
}

void testApp::setup() {
	ofBackground(0);
    pull = ofVec3f(0,0,0);
	preMouseX = 0;
	preMouseY = 0;

}

void testApp:: update() {
     
	cloth.update();
}

void testApp:: draw() {
    cloth.draw();
}


void testApp::mouseDragged(int x, int y, int button) {
	
    ofVec3f mouse = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
	ofVec3f pMouse = ofVec3f(preMouseX, preMouseY, 0);
	ofVec3f drag = mouse - pMouse;
	cout << drag <<endl;
	
	for (int i = 0; i<cloth.particles.size(); i++) {
		Particle* p = &cloth.particles[i];
		float dist = p->pos.distance(pMouse);
		if (p->withinMouseForce(dist)) { 
			p->applyForce(drag);
		}
		
	}
	preMouseX = x;
	preMouseY = y;

}

void testApp::keyPressed(int key) {
	cloth.reset();
}
