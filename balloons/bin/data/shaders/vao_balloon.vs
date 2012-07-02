
in vec3 in_position;
in vec3 in_color;
out vec3 OutColor;

void main()
{
	vec3 eyeCoordinate  =glModelViewMatrix * in_position;
     gl_Position = in_position * glProjectionViewMatrix;
     gl_TexCoord[0] = gl_MultiTexCoord0;
	//gl_Position = ftransform();
     OutColor = in_color;
}
