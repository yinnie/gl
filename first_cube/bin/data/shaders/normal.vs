#version 120
varying vec3 normal;
uniform vec3 lightPosition;
varying float lightIntensity;
uniform float time;


void main()
{   
    vec3 eye = vec3 (gl_Vertex * gl_ModelViewMatrix);
    vec3 normal = normalize(gl_Normal*gl_NormalMatrix);
    normal.y= sin(time);
    //normal.z= sin(time+500);
    normal.x= cos(time);
    vec3 lightVec = normalize(lightPosition - eye);
    vec3 eyeVec = normalize(eye);
    vec3 reflectVec = reflect(-lightVec, normal);
    float spec = max(dot(reflectVec, eyeVec), 0.0);
    spec = pow(spec, 16.0);
    lightIntensity = spec*0.1 + 0.9*max(dot(lightVec, normal), 0.1); 
    vec3 c = vec3 (gl_Color);   
    c.g =normal.y;
    
    c.r =normal.x;
    vec4 pos = gl_Vertex;
      pos.z=cos(time)*3.5;
      pos.x+=sin(time+100)*3.5;
      pos.y+=sin(time+200)*2;
   c.b =pos.z;
//c.b +=sin(time+500)*10;
    
    gl_FrontColor = vec4(c, 1.0);
	//gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}
