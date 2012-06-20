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
#define MAX_PARTICLES  10

class particleSystem {

public:
	
	void setup();
	void update();
	void drawPoints();
	void drawVA();
	
	vector<Particle> particles;
	int numNewParticles;



};


#endif