#pragma once

#include "ofMain.h"



class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void debugDraw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
	    GLfloat x, y, z;
	int iPivot, radius;
		int coneHeight;
	    bool bOutline;
	    ofCamera camera;
	    ofVec3f center;
		
};
