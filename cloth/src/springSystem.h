/*
 *  springSystem.h
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SPRING_SYSTEM_H
#define SPRING_SYSTEM_H
#include "spring.h"
#include "particle.h"
#include "ofMain.h" 


class springSystem  {

public: 
	
	void createSpring(particle a, particle b);
	void update();
	void draw();
	
	vector<spring> springs;
	
};

#endif