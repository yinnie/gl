/*
 study of cloth simulation...study of how particles moove with interconnections. study of verlet integration
 reference: http://cg.alexandra.dk/2009/06/02/mosegaards-cloth-simulation-coding-tutorial/
*/


#include "ofMain.h"
#define TIMESTEP 0.5*0.4

class Particle {
public:
	ofVec3f pos;
	ofVec3f acc;
	ofVec3f last_pos;
	float mass;
	float damping;
	
	Particle() {                 //default constructor
		pos = ofVec3f(0,0,0);
		acc = ofVec3f(0,0,0);
		last_pos = pos;
		mass = 1;
		damping = 0.9;
	}
	Particle(ofVec3f position) : pos(position) {  //we are filling the grid of the cloth with particles..therefore it is position on the grid that 'constructs' a particle
		acc = ofVec3f(0,0,0);
		last_pos = pos;    //do not initialise last_pos as (0,0,0)..it makes the initial drag too big
		mass = 1;
		damping = 0.9;
	}
	void applyForce(ofVec3f f) {
		acc = f/mass;
	}
	void move() {   //verlet integration
		ofVec3f currentPos = pos;
		pos = pos + damping*(pos - last_pos) + acc*TIMESTEP;
		last_pos = currentPos;  //we used last_pos in calculation above..so cannot update it before the above calculation
		acc = ofVec3f(0,0,0);  
	}
	bool withinMouseForce(float dist) {
		if (dist < 10) {
			return true;
		} else {
			return false;
		}
	}
		
	
};

class Spring {
public:
	Particle* a;
	Particle* b;
	float rest_length;
	float k;
	
	Spring(Particle* x, Particle *y) : a(x), b(y) {
		rest_length = 5;
		k = 0.1;
	}
	
	void update() {
		ofVec3f direction = a->pos - b->pos;
		ofVec3f dirNormalised = direction.normalize();
		float distance = a->pos.distance(b->pos);
		ofVec3f springForce = dirNormalised * k * (distance - rest_length);
		a->pos += -1*springForce*0.5;
		b->pos += springForce*0.5;
	}
	
};

class Cloth {
public:
	vector<Particle> particles;
	vector<Spring> springs; 
	int cols; 
	int rows;
	int size;
	
	Cloth (int x, int y, int s) : cols(x), rows(y), size(s) {
		particles.resize(cols*rows);
		fillParticles();
		makeSprings();
	}
	
	void fillParticles() {
		for (int i = 0; i<cols; i++) {
			for (int j =0; j< rows; j++) {
				int lable = i+cols*j;
				ofVec3f gridPos = ofVec3f (100+i*size, 100+j*size, 0);
				particles[lable] = Particle (gridPos);
			}
		}
	}
	
	void makeSprings() {
		for (int i = 0; i<cols; i++) {
			for (int j =0; j< rows; j++) {
				if (i < cols -1) {
					Spring spring (getParticle(i, j), getParticle(i+1, j));
					springs.push_back(spring);
				}
				if (j < rows -1) {
					Spring spring (getParticle(i, j), getParticle(i, j+1));
					springs.push_back(spring);
				}
				if (i < cols-1 && j < rows -1) {
					Spring spring (getParticle(i, j), getParticle(i+1, j+1));
					springs.push_back(spring);
				}
			}
		}
	}
	
	Particle* getParticle(int x, int y) { return &particles[x+cols*y];}
	
	void update() {
		
	     for (int i = 0; i<springs.size(); i++) {
			 springs[i].update();
		 }
		 
		 for (int n = 0; n < 3; n++) {           //a few iterations for the verlet integration to work the best
			 for (int i =0; i<particles.size(); i++) {
				 particles[i].move();
			 }
			 
		 }
	
	}
	void draw() {
		ofSetColor(231, 247, 181);
		ofSetLineWidth(0.1);
		for (int i = 0; i<springs.size(); i++) {
	
			ofPoint p1, p2;
			p1.set (springs[i].a->pos);
			p2.set(springs[i].b->pos);
			ofLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
	
	void reset() {
		fillParticles();
		makeSprings();
	}
		
};




class testApp : public ofBaseApp {
public: 
	testApp();
	void setup();
	void draw();
	void update();
	void mouseDragged(int x, int y, int button);
	void keyPressed(int key);
	
	Cloth cloth;
	ofVec3f pull;
	float preMouseX;
	float preMouseY;
	
};



