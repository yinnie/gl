#include "testApp.h"

//a particle system of strawberries/watermelons that fly towards the viewer from afar
//first create a static system ..points in 3D 

//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
    
	//initiate the points 
    for (int i = 0; i < MAX_PARTICLES ; i++) {
		points[i][0] = ofRandom(ofGetWidth());
		points[i][1] = ofRandom(ofGetHeight());
		points[i][2] = ofRandom(-500, 0);
		
		color[i][0] = 1;
	    color[i][1] = 0.8;
		color[i][2] = 0.5;
		color[i][3] = 0.4;
		
		vel[i][0] = 0;
		vel[i][1] = 0;
		vel[i][2] = 0;
	}
	
	ofDisableArbTex(); //!!!! force any texture created from this point on, to be GL_TEXTURE_2D (normalized uv coords)
	img.loadImage("grad.png");
	va = false;
	vbo = false;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i=0; i < MAX_PARTICLES; i++) {
		points[i][2]+=0;
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
	glEnable(GL_DEPTH_TEST);
	glPointSize(3);
	
    img.getTextureReference().bind();
	glEnable(GL_POINT_SPRITE);
	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
	
    if (va) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		
		glVertexPointer(3, GL_FLOAT, 0, points);
		glColorPointer(4, GL_FLOAT, 0, color);
		
		glDrawArrays(GL_POINTS, 0, MAX_PARTICLES);
		
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	
	}

	else if (vbo){
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		
		glGenBuffers(2, bufferObjects);   //generate buffer object
		
		glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[0]);  //bind buffer object to target..object is still empty
	    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES*3*sizeof(float), points, GL_STATIC_DRAW); //copy data of array into object
		glVertexPointer(3, GL_FLOAT, 0, 0);  
        
		glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[1]);
		glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES*4*sizeof(float), color, GL_STATIC_DRAW);
		glColorPointer(4, GL_FLOAT, 0, 0);
		
		glDrawArrays(GL_POINTS, 0, MAX_PARTICLES);		//send data to GPU
		
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);  //binding 0 is basically unbind 
	}
	
	else {
		glBegin(GL_POINTS);
		    for (int i = 0; i < MAX_PARTICLES; i++) {
				glVertex3f (points[i][0], points[i][1], points[i][2]);
			}
		glEnd();
	
	}
	
	img.getTextureReference().unbind();
	glDisable(GL_POINT_SPRITE);
	
	glDisable(GL_DEPTH_TEST);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("frameRate =" + ofToString(ofGetFrameRate(), 2), 20,20);
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	switch (key) {
		case '1':
			va = true;
			vbo = false;
			break;
		case '2':
			vbo = true;
			va = false;
			break;

		default:
			break;
	}	
}
