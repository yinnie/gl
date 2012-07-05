uniform sampler2D tex0;
varying float lightIntensity;


void main()
{
   vec2 pos = gl_TexCoord[0].st;  
   vec4 col = texture2D (tex0, pos);
    vec4 reflectCol =  gl_Color*lightIntensity*1.5;  
    vec4 newCol = vec4(0,0,0,0);
   newCol = mix (col, reflectCol, 0.7);  //environemnt color, base color, mix ratio	
   gl_FragColor = newCol;
}
