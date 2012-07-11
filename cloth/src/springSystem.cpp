/*
 *  springSystem.cpp
 *  cloth
 *
 *  Created by Yin Liu on 7/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifdef SPRING_SYSTEM_H
#define SPRING_SYSTEM_H
#include "springSystem.h"
#include "ofMain.h" 


void springSystem::createSpring(particle a, particle b){
	
	spring s; 
	s.setup(a, b);
	springS.pushback(s);
	
}


void springSystem::update(){
}

void springSystem::draw(){

	ofSetColor(255);
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_LINES);
	for (int i = 0; i < springs.size(0; i++) {
		mesh.addVertex(springs[i].a.pos);
		mesh.addVertex(springs[i].b.pos);
	}	  
	mesh.draw();
		 
}



#endif

