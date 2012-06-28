uniform sampler2D tex;
int vec3 OutColor;
out gl_FragColor

void main()
{
	gl_FragColor = vec4 (OutColor, 1.0);
}
