#pragma once

#include "ofMain.h"

#define N 100
#define WIDTH 3
#define HEIGHT 5
#define HALF_WIDTH (WIDTH*0.5)
#define HALF_HEIGHT (HEIGHT*0.5)
#define NUM (N*N)
#define DX(i,j) (((j)*(N)) + (i))

static const string VS = "  \
	attribute vec4 pos; \
	attribute vec2 tex; \
	uniform mat4 view_matrix; \
	uniform mat4 projection_matrix; \
	varying vec2 vtex; \
	\
	void main() { \
		gl_Position = projection_matrix * view_matrix * pos;\
		vtex = tex; \
	} ";
	

static const string FS = "  \
	uniform sampler2D texture; \
	varying vec2 vtex; \
	void main() { \
		gl_FragColor = texture2D(texture, vtex); \
	} ";
	
struct Vertex {
	ofVec3f pos;
	ofVec2f tex;
	
	Vertex() {
	}
	
	Vertex(const float& x, const float& y, const float& z, const float& u, const float& v)
		:pos(x,y,z)
		,tex(u,v)
	{
	
	}
	
	void set(const float& x, const float& y, const float& z, const float& u, const float& v) {
		pos.set(x,y,z);
		tex.set(u,v);
	}
	
	
};

struct SimpleMesh {

	int add(const Vertex& v) {
		vertices.push_back(v);
		return vertices.size() - 1;
	}
	
	float* getPtr() {
		return &vertices[0].pos.x;
	}
	
	size_t size() {
		return vertices.size();
	}
	
	size_t getNumBytes() {
		return vertices.size() * sizeof(Vertex);
	}
	
	void assign(size_t num) {
		vertices.assign(num, Vertex());
	}
	
	Vertex& operator[](const unsigned int& dx) {
		return vertices.at(dx);
	}
	
	vector<Vertex> vertices;
};


class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void debugDraw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofShader shader;
		ofMatrix4x4 view_matrix;
		ofMatrix4x4 projection_matrix;
		SimpleMesh mesh;
		
		GLuint vbo;
		GLuint vao;
		GLuint tex;
};
