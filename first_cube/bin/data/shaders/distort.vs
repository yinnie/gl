void main()
{
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	//distorting the teapot
    //first get the z value of the geometry
    vec4 coor = gl_ModelViewMatrix * gl_Vertex;
    coor.x = 0.0 ;
     gl_Position = ftransform();
    vec4 col = gl_Color;
     col.r = 1.0;
     gl_FrontColor = col;

}
