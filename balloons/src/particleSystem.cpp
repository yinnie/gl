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
	
	particles.resize(100);
	
	for (int i = 0; i< particles.size(); i++) {
		
		Particle &p = particles[i];  
		p.pos.set(ofRandom(ofGetWidth()), ofGetHeight(),ofRandom(depth,0));
		p.vel.set(0,0,0);
		p.force.set(0,0,0);
		p.setup();  // initiate radius when drawing spheres
		
		p.color.set(ofColor::fromHsb(ofRandom(65,100), 255, 255));
	    
		particlePos[i][0] = p.pos.x;
		particlePos[i][1] = p.pos.y;
		particlePos[i][2] = p.pos.z;
		particleColor[i].r = p.color.r;
		particleColor[i].g = p.color.g;
		particleColor[i].b = p.color.b;
					
		vbo.setVertexData(particlePos, particles.size(), GL_DYNAMIC_DRAW);
		vbo.setColorData(particleColor, particles.size(), GL_DYNAMIC_DRAW);
					
     }
	
	numNewParticles = 1;
	
}


void particleSystem:: update() {
	
	//update location of the particle    
	
	
	//TO DO: BALLONS SHOULD HAVE VARIABLE SPEEDS AND GOING UP AT DIFFERENT HEIGHT LINKED TO THEIR SIZE
	
	
	GLfloat positions[particles.size()][3];     //array to hold vertex data
	for (int i = 0; i<particles.size(); i++) {
		
		Particle &p  = particles[i];
		
		p.force.set(0, 0, 0); //set the force to be zero at every loop
		
		if (p.pos.y > 0 + p.radius) {
			p.force.y+=0.015;
			//p.force.z+=ofRandom(-0.01, 0.01);
			float noiseAmount = 0.1;
			float noiseStep = 200;
			float t = ofGetElapsedTimef();
			p.force.x += noiseAmount * ofSignedNoise( t *noiseStep);
			//p.force.x += ofNoise(t*0.001);
			p.vel+=p.force;
			p.pos-=p.vel;
			cout << p.pos.y << endl;
		}
		
		else if (p.pos.y <=0 + p.radius) {
			p.pos.y = 0 + p.radius;
			p.pos.z+=ofRandom(-0.2, 0.3);
			p.pos.x+=ofRandom(-0.1, 0.1);

		}
		
		particlePos[i][0] = p.pos.x;
		particlePos[i][1] = p.pos.y;
		particlePos[i][2] = p.pos.z;
		particleColor[i].r = p.color.r;
		particleColor[i].g = p.color.g;
		particleColor[i].b = p.color.b;
			
        vbo.updateVertexData(particlePos, particles.size());
		vbo.updateColorData(particleColor, particles.size());
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

void particleSystem:: drawVbo() {
	
	 vbo.draw(GL_DYNAMIC_DRAW, 1, particles.size());   //use draw vs. drawElements coz we don't have any indices data

}

void particleSystem:: draw() {
	
	for (int i = 0; i < particles.size(); i++) {
		
		img.bind();
		
		ofSetColor(250, 132, 201,0.5);
				Particle & p = particles[i];
		
        ofSphere(p.pos.x, p.pos.y, p.pos.z, p.radius);
		img.unbind();
	}

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





