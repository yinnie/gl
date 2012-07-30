uniform sampler2D tex;
varying float lightIntensity;


void main()
{
    //vec3 lightColor = vec3 (texture2D(tex, gl_TexCoord[0].xy));
	//gl_FragColor = vec4(lightColor * lightIntensity*2.0, 1.0);

    gl_FragColor = gl_Color*lightIntensity;
}
