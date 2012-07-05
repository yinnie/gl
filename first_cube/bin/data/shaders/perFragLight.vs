//per fragment lighting 

uniform vec3 lightPosition;  //to be defined by user

const float specContribution = 0.3;
const float diffuseContribution = 1.0 - specContribution;   //floating numbers need to be everywhere

varying float lightIntensity;


void main()
{
     vec3 ecPosition = vec3( gl_Vertex* gl_ModelViewMatrix);   //vec3 on right hand side is a casting
      vec3 normal = normalize(gl_Normal * gl_NormalMatrix);  //normalize not normalise!!

	vec3 lightVec = normalize (lightPosition - ecPosition);  //this is a direction so it needs to be normalized too

     vec3 viewVec = normalize (-ecPosition);  //all directions are vec3 and all should be normalized

     vec3 reflectVec = reflect (-lightVec, normal);  //how a surface reflects lights depends on the normal at that particular vertex!!  and "-" sign because the reflection is opposite direction of light direction

     //diffuse light:  need angle between light and normal
     float diffuse =  max (dot (lightVec, normal), 0.0);

     //specular light: reflection between reflected light direction and viewVec  
     float spec = 0.0;
     spec = max ( dot (reflectVec, viewVec), 0.0);
     spec = pow (spec, 16.0);

     lightIntensity = spec* specContribution + diffuse * diffuseContribution;
     
     gl_FrontColor = gl_Color;
     gl_Position = ftransform();

}
