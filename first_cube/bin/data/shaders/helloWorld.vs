//uniform float time;

void main() {
     
     //to apply texture...initiate the texcoord
     //gl_TexCoord[0] = gl_MultiTexCoord0;
    //adjust point size according to how far into z the point is
    //first you need to know where all the points are in the eye coordinates 
    vec4 ecPos = gl_ModelViewMatrix * gl_Vertex;  //ecPos is vec4 becoz it is the result of a matrix and a vec3
   
     //float dist = sqrt (ecPos.x*ecPos.x + ecPos.y*ecPos.y + ecPos.z*ecPos.z);
    //float distFactor = 1000.0 / dist;
    //vec4 col = gl_Color;
     //col.r = 0.0;
     //col.g = 0.0;
     //col.b = 255.0; 
     ecPos.z = 0.0;  

    gl_FrontColor = gl_Color;
   
    gl_Position = ecPos;  //this line is the equivalent of the following line
//  gl_Position = gl_ProjectionMatrix * gl_ModelVeiwMatrix * gl_Vertex;
//  or gl_Position = gl_ModelViewProjectionMatrix;

    //the vertex shader computes front and back colors ..which are only READABLE in fragment shader
 }