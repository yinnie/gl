#pragma once

#include "ofMain.h"
#include "particleSystem.h"



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
		void drawCeiling();
	    void drawRoom();
		void drawCircle(int x, int y);
		void AddFace(ofMesh &mesh, ofVec3f a, ofVec3f b, ofVec3f c);
		void AddFace(ofMesh &mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d);

    	particleSystem ps; 
		ofImage img;
		
		ofCamera camera;

		ofVec3f center;
		float depth;
		ofShader shader;
	    bool drawVa, drawVao, drawPoints, useShader, goBalloon, goSpring;
		
};
