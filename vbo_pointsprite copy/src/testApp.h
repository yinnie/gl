
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#define MAX_PARTICLES  100000
 

class testApp : public ofSimpleApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	

    float points[MAX_PARTICLES][3];   //2 dimensional array of points positions
    float color[MAX_PARTICLES][4];   //2 dimensional array of points positions
	float vel[MAX_PARTICLES][3];
	ofImage img;
    bool va;  //use vertex array
	bool vbo;  //use vbo
    GLuint bufferObjects[2];  //uss unsigned integer!!!!! not glint! TWO BUFFER OBJECTS..ONE FOR VERTEX ONE FOR COLOR

};

#endif
