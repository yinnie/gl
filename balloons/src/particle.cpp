/*
 *  particle.cpp
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"


void Particle:: setup() {
	radius = ofRandom(20,25);
	color = ofVec3f(ofRandom(100,255), ofRandom(255), 50);	
}

void Particle:: draw() {
	
}

