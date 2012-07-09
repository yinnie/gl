/*
 *  particleSystem.cpp
 *  particles
 *
 *  Created by Yin Liu on 6/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particleSystem.h"

void particleSystem::setup(int depth) {
	
	particles.resize(500);
	
	numNewParticles = 1;
	dragged = false;
		
	for (int i = 0; i< particles.size(); i++) {
		
		Particle &p = particles[i];  
		p.setup(depth);  // initiate radius when drawing spheres FIRST 
        p.pos = p.restPos; 
		p.vel.set(0,0,0);
		p.force.set(0,0,0);	
     }		
}


void particleSystem:: update() {
	
	//update location of the particle    
	//GLfloat positions[particles.size()][3];     //array to hold vertex data
	
	
	for (int i = 0; i<particles.size(); i++) {
		
		Particle &p  = particles[i];
		
		p.force.set(0, 0, 0); //set the force to be zero at every loop
					
			float randomNumber = ofRandom(30);
			if (randomNumber < 10) {
				p.force.y+=0.00005; 
			}
			else if (randomNumber < 15 ){
				p.force.y+=0.0005;
			}
					 else p.force.y+= 0.03;

				//p.force.z+=ofRandom(-0.01, 0.01);
				float noiseAmount = 0.1;
				float noiseStep = 200;
				float t = ofGetElapsedTimef();
				//p.force.x += noiseAmount * ofSignedNoise( t *noiseStep);
				//p.force.x += ofNoise(t*0.001);
			
		//bouncing and damping against the ceiling
	    if (p.pos.y <=0 + p.radius) {
			float damp = 0.28;
			float k = 0.0003;
			float dist = p.radius - p.pos.y;
			p.bounceForce = ofVec3f(0,-1 * k * dist,0);
		    p.vel = damp*(p.vel + p.bounceForce);
		}

		
		p.vel+=p.force;
		
		p.pos-=p.vel;

	}	
	/*
	//add new particles every frame
	for (int i= 0; i < numNewParticles; i++) {
		Particle &p = particles[i];
		p.pos.set(ofRandom(ofGetWidth()),ofGetHeight(),ofRandom(depth,0));
		p.vel.set(0,0,0);
		p.force.set(0,0,0);
		particles.push_back(p);
		
		if (particles.size() > MAX_PARTICLES) {
			particles.pop_back();
		}
	}
	*/	
}

void particleSystem:: draw() {
	
	for (int i = 0; i < particles.size(); i++) {
	
		Particle & p = particles[i];
	    
		//ofSetColor(255, 255,255);
		//ofSetLineWidth(0.1);
        //ofLine(p.pos.x, 0, p.pos.z, p.pos.x, length, p.pos.z);
		
		ofPushStyle();
		ofSetColor(p.color.x, p.color.y, p.color.z);
		ofSphere(p.pos.x, p.pos.y, p.pos.z, p.radius);	
		ofPopStyle();			
	}		
}



void particleSystem::updateSpring() {
	
	dragOut();
	
	for (int i = 0; i < particles.size(); i++) {
	    Particle &p = particles[i];
		
		float stretch = p.pos.y - p.restPos.y;
		p.springForce.y = -1 * p.k * stretch;
		p.vel.y = p.damp * (p.vel.y + p.springForce.y);
		p.pos.y += p.vel.y;
	}
}


void particleSystem:: dragOut() {
	
	for (int i = 0; i < particles.size(); i++) {
		Particle &p = particles[i];
		
		if (dragged) {
			float displacement = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 190);
			float distToDrag = sqrt((ofGetMouseX()-p.pos.x)* (ofGetMouseX()-p.pos.x) );
		    float offset = ofMap(distToDrag, 0, ofGetWidth()*10, displacement, 0);
		    p.pos.y = p.restPos.y + displacement;
			
		}
	}
}

void particleSystem:: checkBoundary(int depth) {
    
	for (int i = 0; i < particles.size(); i++) {
	
		Particle & p = particles[i];
		
		if (p.pos.x-p.radius < 0 ) {
			p.pos.x = p.radius;
			p.vel.x *= -0.9;
		}
		else if (p.pos.x + p.radius > ofGetWidth()) {
			p.pos.x = ofGetWidth() - p.radius;
			p.vel.x *= -0.9;
		}

		if (p.pos.y-p.radius < 0 ) {
			p.pos.y = p.radius;
			p.vel.y *= -0.9;
		}
		else if (p.pos.y + p.radius > ofGetHeight()) {
			p.pos.y = ofGetHeight() - p.radius;
			p.vel.y *= -0.9;
		}
			
		if (p.pos.z-p.radius > 0 ) {     //depth is negative 
			p.pos.z = p.radius;
			p.vel.z *= -0.9;
		}
		else if (p.pos.z + p.radius < depth) {    //depth is negative 
			p.pos.z = ofGetHeight() + p.radius;
			p.vel.z *= -0.9;
		}
	}	
}

void particleSystem:: drawVao() {
	
	//do all the GL stuff in draw
	
	GLfloat vertexdata[particles.size()][3];
	GLfloat colordata[particles.size()][3];
	
	for (int i = 0; i<particles.size(); i++) {
		Particle &p = particles[i];
		
		vertexdata[i][0] = p.pos.x;
		vertexdata[i][1] = p.pos.y;
		vertexdata[i][2] = p.pos.z;
		colordata[i][0] = p.color.x;
		colordata[i][1] = p.color.y;
		colordata[i][2] = p.color.z;
		
	}
	
	//make vao 
	glGenVertexArrays(1, &vao);   //use & because the parameter needed is a pointer 
	//activate vao
	glBindVertexArray(vao);
	//make vbos
	glGenBuffers(2, vbo);         //vbo is already a pointer since it is an array   
	
	//activate vbos..i.e. what type of vbo is this?
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	//copy data into vbo
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*particles.size(), vertexdata, GL_DYNAMIC_DRAW);
	//point this data to an attribute index..
	//arguments: what index, no. of components per attribute, type, normalise as integers?, stride, displacement to first element in array)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, 0); 
	//enable vao array 
    glEnableVertexAttribArray(0);
		
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*particles.size(), colordata, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);	
	
}


void particleSystem:: drawPoints() {
	
	//glPointSize(30);
		 glBegin(GL_POINTS);
				for (int i = 0 ; i < particles.size(); i++) {
					Particle &p = particles[i];
					glVertex3fv(p.pos.getPtr());  //getPtr() returns pointer therefore use 3fv instead of 3f
				}
	     glEnd();	    
}

void particleSystem:: drawVA() {
	
	glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
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





