/*
 *  particle.cpp
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"


void Particle:: setup(int depth) {
	radius = ofRandom(5,7);
	color = ofVec3f(ofRandom(100,255),ofRandom(50, 200), 50);	
	restPos = ofVec3f(ofRandom( ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(depth,0));
	damp = ofRandom(0.8, 0.98);
	k = 0.1;
}

void Particle:: draw() {
	
}

