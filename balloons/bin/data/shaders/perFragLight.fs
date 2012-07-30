uniform sampler2D tex0;
uniform float time;
varying float lightIntensity;


void main()
{  
/*
   vec2 pos = gl_TexCoord[0].st;  
   vec4 col = texture2D (tex0, pos);
    vec4 reflectCol =  gl_Color*lightIntensity*1.5;  
    vec4 newCol = vec4(0,0,0,0);
   newCol = mix (col, reflectCol, 0.7);  //environemnt color, base color, mix ratio
*/	
   vec4 col1 = vec4(1.0, 0, 0,0);
   vec4 col2 = vec4(1.0, 1.0, 0,0);
   float loopDuration = 500.0;
   float curTime = mod(time, loopDuration);  
float curlerp = curTime / loopDuration;
    vec4 newCol;
   newCol = mix (col1, col2, curlerp);
    gl_FragColor = newCol;
}
