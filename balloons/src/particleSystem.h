/*
 *  particleSystem.h
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLES_PARTICLESYSTEM_h
#define PARTICLES_PARTICLESYSTEM_h
#include "particle.h"
#define MAX_PARTICLES 50
#include "ofMain.h"

class particleSystem {

public:
	
	void setup(int depth);
	void update();
	void drawPoints();
	void drawVA();
	void draw();
	void drawVbo();
	
	vector<Particle> particles;
	int numNewParticles;
    ofImage img;
    ofVbo vbo;    
	ofVec3f particlePos[MAX_PARTICLES]; 
	ofFloatColor particleColor[MAX_PARTICLES]; 
};


#endif