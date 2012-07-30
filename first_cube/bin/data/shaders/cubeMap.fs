uniform samplerCube cubeMap;
varying float lightIntensity;
varying vec3 reflectVec;
const float mixRatio = 0.2;
const vec3 baseColor = vec3(0.0, 1.0, 0.0);
void main()
{

    vec3 envColor = textureCube(cubeMap, reflectVec).rgb;
    //either put vec3 at front or do texture(xxx,xxx).rgb...otherwise glsl doesn't know if you want vec3 or vec4 both of which can be returned by that function
    vec3 c = mix(baseColor*lightIntensity, envColor, mixRatio); 
    gl_FragColor =vec4( c, 1.0);

}
