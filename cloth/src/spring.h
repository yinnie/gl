/*
 *  spring.h
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SPRING_h
#define SPRING_h
#include "particle.h" 
#include "ofMain.h" 

class spring  {
	
public:
		
	float strength; 
	float rest_length; 
	void setup(particle a, particle b);
	void createSpring(particle a, particle b);
	void update();	
	
};
#endif