void Main() {
	
	//finally set the pos to be that actual position rendered
	gl_Position = ftransform();

	//modify our color
	vec4 col = gl_Color;
	//col.b += noiseB;
	col.b = 1.0;
    col.g = 1.0;
    col.r = 0.0;
	gl_FrontColor =  col;	
}
