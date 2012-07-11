/*
 *  particleSystem.cpp
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particleSystem.h"
#include "ofMain.h" 

void particleSystem::setup() {
    
	//particles.resize(200);
	
	/*
    vector<particle>::iterator it = particles.begin();
	while (it != particles.end()) {
		it->createParticle();
	}
    */
}

void particleSystem::createParticle(int i, int j, float length) {
	particle p;
	p.setup(i, j, length);
	particles.push_back(p);
	if (particles.size() > MAX_PARTICLE_SIZE) {
		particles.pop_back();
	}
	
}

void particleSystem::update() {

}

void particleSystem::draw() {
	
	glPointSize(4);
	ofSetColor(255, 0, 0);
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);
	vector<particle>::iterator it = particles.begin();
	while (it != particles.end()) {
		mesh.addVertex(it->pos);
		it++;
	}
	mesh.draw();
	
}

