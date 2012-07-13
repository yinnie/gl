/*
 study of cloth simulation...study of how particles moove with interconnections. study of verlet integration
 recourse: http://cg.alexandra.dk/2009/06/02/mosegaards-cloth-simulation-coding-tutorial/
 
 a cloth is made of particles and forces between the particles. 
 The in-between forces are like springs that exerts contraining forces on both sides of that force. So the particles are pulling each other
 
 We need: 
 a particle class
 a spring class
 a cloth class (made of a vector of particles and a vector of springs) 
 */


#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#define TIMESTEP 0.5

class Particle {
public:
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;  //here we dont use force becoz force is now seen as external factor
	ofVec3f last_pos;
	float mass;   //to do this properly we want particles to have masses
	float damping;
	
	Particle () {
		mass = 1;
		damping = 0.9;
		pos = ofVec3f(0,0,0);
		last_pos = pos;
		vel = ofVec3f(0,0,0);
		acc = ofVec3f(0,0,0);
	}
	
	
	//what does this particle do? it receives forces
	void applyForce(ofVec3f f) {
		acc = f/mass;
	}
	
	void move() {                              
		acc = ofVec3f (0,0,0);
		ofVec3f currentPos = pos;                     //saving current position before calculation
		pos = pos + (pos-last_pos) + damping * acc*TIMESTEP;    //the new position....verlet integration
	    last_pos = currentPos;          
	}
	
	void draw() {
		glPointSize(5);
		ofPoint(pos.x, pos.y, pos.z);
	}	
};

class Spring {
public:	
	Particle* a;
	Particle* b;
	
	float rest_length;
	float k;
	
	Spring() {
		k = 0.1;
		rest_length = 5;
		a = new Particle();
		b = new Particle();
	}
	
	void createSpring(Particle* x, Particle* y) {  //note x is pulling particle; y is pulled particle
		a = x;
		b = y;
		ofVec3f dir = a->pos - b->pos;
		ofVec3f dirNormalized = dir.normalize();
		float distance = a->pos.distance(b->pos);
		ofVec3f springForce = -1 * dirNormalized * k * (distance - rest_length);
		a->applyForce(springForce);
		b->applyForce(-1 * springForce);
	}
	
	void draw() {
		ofPoint p1, p2;
		p1.set(a->pos.x, a->pos.y, a->pos.z);
		p2.set(b->pos.x, b->pos.y, b->pos.z);
		ofLine(p1,p2);
	}	
};

class Cloth {
public:	
	vector<Particle> particles;
	vector<Spring> springs;
	ofVec3f center;
	int cols;
	int rows;
	int size;
	
	Cloth (int x, int y, int s) {
		cols = x;
		rows = y;
		size = s;
		
		particles.resize(x*y);
		center = ofVec3f (x*s*0.5, y*s*0.5, 0);
	}
	
	
	void applyForce(ofVec3f f) {
		//this force is received by all the particles..such as a pull..or wind (may require more complicated math).gravity..
		for (int i = 0; i<particles.size(); i++) {
			particles[i].applyForce(f);
		}
	}
	
	//all the springforces come into play..imagine this is not contingent on the fore..it is a constant thing that is always going...
	//meaning that the force is determined by the distance...so when distance is at rest length..of course there is no force..
	//otherwise there is always force..
	
	void applySprings() {
		//who are those particle a and particle b for each spring? 
		//in the spring class..in functin createSpring..u r saying no matter who are those particles..just do this..
		//now you need to tell the program on whom are you going to apply this function
		
		for (int i = 0; i<cols; i++) {
			for (int j = 0; j<rows; j++) {
				
				if (i < cols -1) {          //structural springs
					int label = i + rows*j;
					for (int s = 0; s<springs.size(); s++) {
						springs[i].createSpring(&particles[label], &particles[label+1]);
					}
					
				}
				
			}
		}
	}
	
	void draw(){
		ofSetColor(255,0,0);
		for (int i = 0; i < particles.size(); i++) {
			particles[i].draw();
		}
		ofSetColor(255);
		for (int i = 0; i<springs.size(); i++) {
			springs[i].draw();
		}
	}
	
};


class testApp : public ofBaseApp{
	public:
	    testApp();  //constructor 
		void setup();
		void update();
		void draw();
	void mouseDragged(int x, int y, int button);
	
	Cloth cloth;
	ofVec3f pull;
				
};

#endif
