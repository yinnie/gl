/*
 *  particleSystem.h
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLE_SYSTEM_h
#define PARTICLE_SYSTEM_h
#include "particle.h" 
#include "ofMain.h"

#define MAX_PARTICLE_SIZE 500

class particleSystem  {

public: 
	void setup();
	void update();
	void draw();
	void createParticle(int i, int j, float length);
	
	vector<particle> particles;
	
	
};
#endif