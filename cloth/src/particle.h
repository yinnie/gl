/*
 *  particle.h
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLE_h
#define PARTICLE_h
#include "ofMain.h" 

class particle  {
	
public:
	void setup(int i, int j, float length);
	void update();
	
	ofVec3f	pos;
	ofVec3f vel;
	ofVec3f force;
	
};

#endif