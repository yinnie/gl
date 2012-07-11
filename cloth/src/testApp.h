#pragma once

#include "ofMain.h"
#include "cloth.h" 

class testApp : public ofBaseApp{
	
	//cloth is basically a grid of points. 
	//between every two points there a spring. a structural spring. 
	//then at every other point there is another spring. 
	//the mouse exerts a force. who receives the force? the cloth..in reality it is the particles that get the force..
	//because particles are displaced from their rest position...the springs that are between them thus exert forces on the two ends
	//of that spring. 
	//finally add shaders to change colors of the indivisual 'particles' 
	
	
	
	public:
		void setup();
		void update();
		void draw();
	Cloth cloth;
	
	float length;
				
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
			
};
