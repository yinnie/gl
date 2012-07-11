/*
 *  cloth.h
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CLOTH_h
#define CLOTH_h
#include "springSystem.h"
#include "particleSystem.h"


class Cloth {

public: 
	void setup(float);
	void draw();
	void addforce(float x, float y);
	void update();
	
	
	particleSystem ps;
	springSystem springS; 
	
	ofShader ParticleShader;
	ofShader SpringShader;	
	
	float length;   //gap of the grid 
	int cols;   //number of columns
	int rows;   //number of rows
};

#endif
