/*
 *  particle.h
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLES_PARTICLE_h
#define PARTICLES_PARTICLE_h
#include "ofMain.h" 


class Particle {

	public :
	        
	void setup();
	void draw();
	
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f force;
	ofFloatColor color;
	int radius;

};

#endif