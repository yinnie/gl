//per fragment lighting 

uniform vec3 lightPosition;  //to be defined by user

varying float lightIntensity;
varying vec3 reflectVec;

void main()
{
     vec3 ecPosition = vec3( gl_Vertex* gl_ModelViewMatrix);   //vec3 on right hand side is a casting
     vec3 eyeP = normalize(ecPosition);
      vec3 normal = normalize(gl_Normal * gl_NormalMatrix);  //normalize not normalise!!

	vec3 lightVec = normalize (lightPosition - ecPosition);  //this is a direction so it needs to be normalized too
     float lightIntensity =  max (dot (lightVec, normal), 0.0);


     vec3 reflectVec = reflect (eyeP, normal);       
     
     gl_FrontColor = gl_Color;
     gl_Position = ftransform();

}
