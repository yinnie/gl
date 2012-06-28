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
	void drawVao();
	
	vector<Particle> particles;
	int numNewParticles;
    ofImage img;
    
	GLuint vao;             //handle for vao
	GLuint VBO[2];          //handle for two buffers..capitalise to differenciate from OF name conventions
	
	
};


#endif