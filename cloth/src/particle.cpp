/*
 *  particle.cpp
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"

void particle::setup(int i, int j, float length) {
	pos.x = 100 + i*length;
	pos.y = 100 + j*length;
	pos.z = 0;
	vel = ofVec3f (0,0,0);
	force = ofVec3f (0,0,0);
	
}

void particle::update() {
    
	vel += force;
	pos += vel;
	
}