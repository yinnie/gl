#pragma once

#include "ofMain.h"



class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void debugDraw();
		
	int radius;
	ofVec3f center;
	    float rotation;
	bool bDrawWireframe;
	float angle;
	
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
