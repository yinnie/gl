#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofSetFrameRate(60);
	ofBackground(22,33,44);

	// Shader + VAO/VBO
	// -----------------

	// create shader program
	shader.setupShaderFromSource(GL_VERTEX_SHADER, VS);
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER, FS);
	shader.linkProgram();

	GLint pos_attrib = glGetAttribLocation(shader.getProgram(), "pos");
	GLint tex_attrib = glGetAttribLocation(shader.getProgram(), "tex"); 
	printf("TEX: %d\n", tex_attrib);
	
	// setup matrices to replace GL_MODELVIEW and GL_PROJECTION
	view_matrix.translate(0.0f,0.0f,-10.0f);
	projection_matrix.makePerspectiveMatrix(65.0f, ofGetWidth()/ofGetHeight(), 0.1f, 100.0f);
	
	// create the mesh  (of N by N points)
	float di = float(WIDTH) / N;
	float dj = float(HEIGHT) / N;

	mesh.assign(NUM);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			mesh[DX(i,j)].set(i * di, j * dj, 0,  i/float(N), 1.0 - j/float(N));
		}
	}
	
	// create VBO & VAO
	glGenVertexArraysAPPLE(1, &vao);
	glBindVertexArrayAPPLE(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh.getNumBytes(), mesh.getPtr(), GL_STATIC_DRAW); // pass data to vbo

	
	glEnableVertexAttribArray(pos_attrib); // enable vertex attribs for the pos.
	glEnableVertexAttribArray(tex_attrib); // enable vertex attribs for the texcoord.
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, pos)); // where to find the pos atribute
	glVertexAttribPointer(tex_attrib, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, tex)); // where to find the pos atribute

	// Texture
	// ----------
	ofImage img;
	if(!img.loadImage("http://www.roxlu.com/assets/downloads/freakday.png")) {
		printf("cannot load.\n");
	}
	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.getWidth(), img.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixels());
	
}


//--------------------------------------------------------------
void testApp::draw(){
	glEnable(GL_BLEND);
	// translate to center.
	view_matrix.setTranslation(-HALF_WIDTH, -HALF_HEIGHT, -10.0f);

	// draw with our shader.	
	shader.begin();
	
		// we assign our texture to the texture unit 2 (only showing that we're not using the default (0) unit
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE2);
		shader.setUniform1i("texture", 2);
		glBindTexture(GL_TEXTURE_2D, tex);

	
		shader.setUniformMatrix4f("view_matrix", view_matrix);
		shader.setUniformMatrix4f("projection_matrix", projection_matrix);
		
		glBindVertexArrayAPPLE(vao);
		glDrawArrays(GL_POINTS, 0, mesh.size());
	shader.end();
	
}

void testApp::debugDraw() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, ofGetWidth()/ofGetHeight(), 0.1, 100.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-HALF_WIDTH,-HALF_HEIGHT,-10.0f);
	
	glPointSize(1);
	glBegin(GL_POINTS);
		for(int i = 0; i < N; ++i) {
			for(int j = 0;  j < N; ++j) {
				glVertex3fv(mesh[DX(i,j)].pos.getPtr());
			}
		}
	glEnd();

}

//--------------------------------------------------------------
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