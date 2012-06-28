void main()
{
	gl_FrontColor = gl_Color;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	//distorting the teapot
    //first get the z value of the geometry
    vec4 coor = gl_ModelViewMatrix * gl_Vertex;
    coor.x = 0 ;
     gl_Position = ftransform();


}
