#pragma once

#include "ofMain.h"
#include "ofxCubeMap.h"




class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void debugDraw();
		
	ofShader shader;
	ofEasyCam cam;
	ofImage img;
	ofxCubeMap cubeMap;
	
};
