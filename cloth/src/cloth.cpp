/*
 *  cloth.cpp
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "cloth.h"

void Cloth::setup(float length) {
	
    cols = 20;
	rows = 20;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			ps.createParticle(i, j, length);
			//need to initiate the particles...like substituting the 'existing' particles with these...
		}
	}	
	
	particle a;
	particle b;
	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			ps.createParticle(i, j, length);
		}
	}
	
    for (int i = 0; i < ps.particles.size(); i++) {
		springS.createSpring(ps.particles[i], ps.particles[i+1]);
	}

/*
			particle a = ps[(i + cols*j)];
			particle b = ps[(i+ cols*j +1)];
*/
	
	//    ParticleShader.load("particle.vs", "particle.fs");
	//    SpringShader.load("spring.vs", "spring.fs");
}

void Cloth::update() {

}

void Cloth::draw() {
	
	//ParticleShader.begin();
    ps.draw();
	//ParticleShader.end();
	
	//SpringShader.begin();
    springS.draw();	
	//SpringShader.end();
}


void Cloth::addforce(float x, float y) {
}
