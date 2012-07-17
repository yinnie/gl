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

#define TIMESTEP 0.5*0.1

class Particle {
public:
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;  //here we dont use force becoz force is now seen as external factor
	ofVec3f last_pos;
	float mass;   //to do this properly we want particles to have masses
	float damping;
	
	Particle() {
		mass = 1;
		damping = 0.9;
		pos = ofVec3f(0,0,0);
		last_pos = pos;
		vel = ofVec3f(0,0,0);
	}
	
	Particle (ofVec3f position) {    //pos is what defines a particle
		pos = position;              //pass in an argument and pass to pos. you can't set pos to a certain position without passing
		mass = 1;
		damping = 0.9;
		last_pos = pos;
		vel = ofVec3f(0,0,0);
		acc = ofVec3f(0,0,0);
	}
	
	
	//what does this particle do? it receives forces
	void applyForce(ofVec3f f) {
		acc = f/mass;
        move();
	}
	
	void move() {                              
		
		ofVec3f currentPos = pos;                               //saving current position before calculation
		pos = pos + (pos-last_pos) + damping * acc*TIMESTEP;    //the new position....verlet integration
	    last_pos = currentPos;  
		acc = ofVec3f (0,0,0);
        
	}
	
	void draw() {
		ofCircle(pos.x, pos.y, 3.5);
	}	
};

class Spring {
public:	
	Particle* a;
	Particle* b;
	
	float rest_length;
	float k;
	
	//separate the spring creation from the spring force application
	
	//spring creation is just to to pair two. since creating springs from two particles is like saying making a spring from these...it 
	//means that probably you can just set that as part of the constructor of the spring itself. 
	Spring(Particle* x, Particle* y) : a (x), b(y)   //!!! passing x and y into a and b
	{
		k = 0.1;
		rest_length = 5;
	}
	
	void applySpring() {  
	
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

	int cols;
	int rows;
	int size;
	
	Cloth (int x, int y, int s) {
		
		cols = x;
		rows = y;
		size = s;
			
	    particles.resize(cols*rows);    //must use resize to initialise the vector arrays
		
			for (int i = 0; i<cols; i++) {	
			    for (int j = 0; j<rows; j++) {
                     int label = i + cols*j;
					ofVec3f thispos = ofVec3f (i*size, j*size, 0);
				    particles[label] = Particle(thispos);               //???? is this a good way to initialise particles??
				}
			}		
		createSprings();
	}
	
	Particle* getParticle(int x, int y) {
		return &particles[x+cols*y]; 
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
	
	void createSprings() {
		//who are those particle a and particle b for each spring? 
		//in the spring class..in functin createSpring..u r saying no matter who are those particles..just do this..
		//now you need to tell the program on whom are you going to apply this function
		       
		for (int i = 0; i<cols; i++) {
			for (int j = 0; j<rows; j++) {
				//structural springs
				if (i < cols -1) { 
					Spring spring = Spring(getParticle(i,j), getParticle(i+1, j));
				    springs.push_back(spring);                //springs are initiated one by one..so use push back
				}
					
				if (j < rows -1) {
					Spring spring =Spring(getParticle(i,j), getParticle(i, j+1)); 
				    springs.push_back(spring);
				}
			 }				
			}
	}
	
	void draw(){
		ofSetColor(255, 255,255);
				for (int i = 0; i < particles.size(); i++) {
					particles[i].draw();
				}
		for (int i = 0; i<springs.size(); i++) {
			springs[i].draw();
		}
	}
		
	void update() {
		for (int i = 0; i<springs.size(); i++) {
			cout << springs.size() << endl;
			springs[i].applySpring();
		}
		for (int i = 0; i < particles.size(); i++) {
			particles[i].move();
		}
	}
	
    void reset() {
		for (int i = 0; i<cols; i++) {	
			for (int j = 0; j<rows; j++) {
				int label = i + cols*j;
				ofVec3f thispos = ofVec3f (i*size, j*size, 0);
				particles[label] = Particle(thispos);               //???? is this a good way to initialise particles??
				cout << "particles" << particles[i].pos <<endl;
			}
		}
	
	}
	
};


class testApp : public ofBaseApp{
	
	public:
	    testApp();  
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
	
	Cloth cloth;
	ofVec3f pull;
	ofVec3f center;
	bool mouseDrag;
				
};

#endif
