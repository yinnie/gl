
varying float lightIntensity;


void main()
{

	gl_FragColor = gl_Color * lightIntensity;
}
