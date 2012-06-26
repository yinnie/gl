#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	
	coneHeight = 500;
	center = ofVec3f (ofGetWidth()/2, ofGetHeight()/2, 0);	
	
	GLfloat ambient[] = {0.5, 0, 0.5f, 1.0f};
	GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat specular[] = {1.0, 1.0f, 1.0f, 1.0f}; 
	GLfloat specref [] = {1.0f, 1.0f, 1.0f, 1.0f}; //specular reflectance of the material
	GLfloat spotDir [] = {0, -1.0f, 0};  //directin of the spotlight
	
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir); 
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 100.0f);  //change this angle if you dont see the specular light spot
	//when the parameter is just one number you use lightf instead of lightfv
		
	glEnable(GL_COLOR_MATERIAL);   //enable color tracking 
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); //only tracking colors for ambient and diffuse light
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	
	//glShadeModel(GL_FLAT);   //using the current color for the next vertex
    glShadeModel(GL_SMOOTH);  //interpolate the color between vertices;
	glFrontFace(GL_CW); //to say clockwise wound is frot facing..becoz we r using triangle fans
	//glEnable(GL_CULL_FACE);   //decide whether to draw the backface or not to improve efficiency
 	glPolygonMode(GL_BACK, GL_LINE);    //wireframe   use GL_LINE not GL_LINES
	
	ofBackground(0, 0, 0);	
	bOutline = false;
	iPivot = 1;
    radius = 150;
	
	//antialiasing
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*   fog effect...
    GLfloat	lowlight [] = {0.3f,0.3f, 0.3f, 0.3f};
	glClearColor(0, 0.3f, 0.5f, 0.7f);
	glEnable(GL_FOG);
	glFogfv(GL_FOG_COLOR, lowlight);
	glFogf(GL_FOG_START, 5.0f);
	glFogf(GL_FOG_END, 30.0f);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	*/
	camera.begin();
	
	//draw world below 
	GLfloat lightPosMirror [] = {ofGetWidth()/2, ofGetHeight()/2-400, 200};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosMirror); //move light below floor
	glEnable(GL_LIGHT0);
	
	ofPushMatrix();
	
		ofTranslate(center);
		
		glFrontFace(GL_CCW);  //geometry reversed underneath
		glScalef(1.0f, -1.0f, 1.0f);
		
		//sphere
		//ofSetColor(0, 0, 255);
		ofSphere(0, radius, 0, radius);
		
		//top 
		glBegin(GL_TRIANGLE_FAN); 
		
		glVertex3f(0, coneHeight, 0);
		for (double angle = 0.00; angle <= (4.00 *PI); angle += PI/16 )   //maximum value of angle needs to be bigger than 2PI
		{   
			x = 150*cos(angle);
			z = 150*sin(angle);
			if ( (iPivot%2) == 0) glColor3f(0.5f, 1.0f, 0);
			else glColor3f(1.0f, 0.5f, 1.0f);
			iPivot ++;
			glVertex3f(x, radius, z);
		}
		glEnd();
		
		//bottom
		glBegin(GL_TRIANGLE_FAN); 
		
		glVertex3f(0, 0,0);
		for (double angle = 0.00; angle <= 4.00*PI; angle += PI/16 ) 
		{   
			x = 150*cos(angle);
			z = 150*sin(angle);
			if ( (iPivot%2) == 0) glColor3f(1.0f, 0.85f, 0.4f);
			else glColor3f(0.5, 1.4f, 1.4f);
			
			glVertex3f(x, radius, z);
			iPivot ++;
		}
		glEnd();
		
		glFrontFace(GL_CW);
	
	ofPopMatrix();

	
	//draw ground transparently 
	ofPushMatrix();
		ofTranslate(center);
		
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		//draw a ground surface 
		GLfloat step1;
		GLfloat step2;
	    GLfloat step;
		int count = 0;
		glShadeModel(GL_FLAT);
		
		for (step1 = 2000; step1 > -2000 ; step1 -= step) 
		{  
			glBegin(GL_TRIANGLE_STRIP);                        //glbegin() inside the for loop
			for (step2 = -2000; step2 < 2000; step2 += step) {
				
				if (count %2 == 0) {
					glColor4f(0.5f, 0.5f, 0, 0.5f);   //need alpha here due for blending Func
				} else {
					glColor4f(0, 0, 0.5f, 0.5f);
				}
				glVertex3f(step1, 0, step2);
				glVertex3f(step1 + step, 0, step2);
				count++;
			}
			glEnd();
			
		}
		
		glShadeModel(GL_SMOOTH);
	ofPopMatrix();
	
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	
	
	
	//draw above ground
	//put light above ground
	GLfloat lightPos [] = {ofGetWidth()/2, ofGetHeight()/2+400, 200}; 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	
	ofPushMatrix();
		ofTranslate(center);
	
		//sphere
		ofSetColor(150, 150, 0);
		ofSphere(0, radius, 0, radius);
		
		//top 
		glBegin(GL_TRIANGLE_FAN); 
		
			glVertex3f(0, coneHeight, 0);
			for (double angle = 0.00; angle <= (4.00 *PI); angle += PI/16 )   //maximum value of angle needs to be bigger than 2PI
			{   
				x = 150*cos(angle);
				z = 150*sin(angle);
				if ( (iPivot%2) == 0) glColor3f(0.5f, 1.0f, 0);
				else glColor3f(1.0f, 0.5f, 1.0f);
				iPivot ++;
				glVertex3f(x, radius, z);
			}
		glEnd();
		
		//bottom
		glBegin(GL_TRIANGLE_FAN); 
		
			glVertex3f(0, 0,0);
			for (double angle = 0.00; angle <= 4.00*PI; angle += PI/16 ) 
			{   
				x = 150*cos(angle);
				z = 150*sin(angle);
				if ( (iPivot%2) == 0) glColor3f(1.0f, 0.85f, 0.4f);
				else glColor3f(0.5, 1.4f, 1.4f);
				
				glVertex3f(x, radius, z);
				iPivot ++;
			}
		glEnd();
		
    glPopMatrix();
		
	
	camera.end();
}

void testApp::update(){
   
	
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
    float rotateAmountX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
	float rotateAmountY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 180);
	ofVec3f furtherestPoint = ofVec3f (0, 200, -600);
	ofVec3f directionToFurtherestPoint = furtherestPoint - center;
	ofVec3f directionToFurtherestPointRotatedX = directionToFurtherestPoint.rotate(rotateAmountX, ofVec3f(0,1,0));
	ofVec3f directionToFurtherestPointRotatedY = directionToFurtherestPoint.rotate(rotateAmountY, ofVec3f(1,0,0));
	camera.setPosition(center + directionToFurtherestPointRotatedX + directionToFurtherestPointRotatedY);
	camera.lookAt(center + coneHeight/2);
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}