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
	        
	void setup(int depth);
	void draw();
	
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f force;
	ofVec3f color;
	ofVec3f bounceForce;     //damping/springy motion when the balloon hits the ceiling
	int radius;             //also serves as mass
	
    float k;                //hook's law coefficient
	float damp; 
    ofVec3f springForce;     //when the balls are behaving like springs
	ofVec3f restPos;        //rest position of the spring
};

#endif