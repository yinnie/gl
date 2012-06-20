/*
 *  particleSystem.cpp
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particleSystem.h"

void particleSystem::setup() {
	
	particles.resize(10);
	
	for (int i = 0; i< particles.size(); i++) {
		
		Particle &p = particles[i];  //p is declared as a refenrence variable..similar to pointer
		p.pos.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(-2000,0));
		p.vel.set(0,0,0);
		p.force.set(0,0,0);
	}
	
	numNewParticles = 1;
}


void particleSystem:: update() {
	
	//update location of the particle
	for (int i = 0; i<particles.size(); i++) {
		
		Particle &p  = particles[i];
		
		p.force.set(0, 0, 0); //set the force to be zero at every loop
		
		p.force.z+=0.01;
		p.force.y+=ofRandom(-0.01, 0.01);
		p.force.x+=ofRandom(-0.01, 0.01);
		
		p.vel+=p.force*0.5;
		p.pos+=p.vel*0.5;
	}
	
	//add new particles every frame
	for (int i= 0; i < numNewParticles; i++) {
		Particle &p = particles[i];
		p.pos.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(-3000,0));
		p.vel.set(0,0,0);
		p.force.set(0,0,0);
		particles.push_back(p);
		
		if (particles.size() > MAX_PARTICLES) {
			particles.pop_back();
		}
	}
	
	
}

void particleSystem:: drawPoints() {
	
	glEnable(GL_POINT_SPRITE);
	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
	ofSetColor(200, 200, 0, 0.3);
	glPointSize(5);

		 glBegin(GL_POINTS);
				for (int i = 0 ; i < particles.size(); i++) {
					Particle &p = particles[i];
					glVertex3fv(p.pos.getPtr());  //getPtr() returns pointer  therefore use 3fv instead of 3f
				}
	     glEnd();
	
	glDisable(GL_POINT_SPRITE);
	
    
}

void particleSystem:: drawVA() {
	//glEnable(GL_POINT_SPRITE);
//	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
	ofSetColor(200, 200, 0, 0.3);
	glPointSize(5);
	
		glEnableClientState(GL_VERTEX_ARRAY);
		GLfloat positions[particles.size()][3];
		
		for (int i=0; i<particles.size(); i++) {
			Particle &p = particles[i];
			
			positions[i][0] = p.pos.x;
		    positions[i][1] = p.pos.y;
		    positions[i][2] = p.pos.z;
			
		}
		glVertexPointer(3, GL_FLOAT, 0, positions);
		glDrawArrays(GL_POINTS, 0, particles.size());
	    glDisableClientState(GL_VERTEX_ARRAY);	
	
	glDisable(GL_POINT_SPRITE);
}


