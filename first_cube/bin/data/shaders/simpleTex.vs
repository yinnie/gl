#version 120

uniform vec3 lightPos;
varying float lightIntensity;

const float diffCont = 0.3;
const float specCont = 1- diffCont;


void main()
{    
    vec3 eyeCoordinate = vec3(gl_Vertex * gl_ModelViewMatrix);
    vec3 view = normalize ( -eyeCoordinate);
    vec3 lightDir = normalize (lightPos - eyeCoordinate);
    vec3 normal = normalize(gl_Normal * gl_NormalMatrix);

    //diffuse light is not viewing dir dependent, it is only determined by relative light pos and normal
    float diff = max(dot(lightDir, normal), 0.0); 

     //specular light is veiwing direction dependent 
     vec3 reflectVec = reflect (lightDir, normal);
     float spec = max(dot(reflectVec, view), 0.0);
     spec = pow(spec, 16.0);
     
     lightIntensity = spec * specCont + diffCont * diff;
  
	gl_FrontColor = gl_Color;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = ftransform();
}
