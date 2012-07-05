varying vec4 vary;

void main () {
       
      vary = clamp(gl_Vertex, 0.0, 1.0);
       vec4 pos  = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
       

       
       gl_Position = pos;      
       gl_FrontColor = gl_Color;

}