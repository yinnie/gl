

void main () {
         
       vec4 pos  = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
       pos.x = pos.x * 0.5;
       pos.y = pos.y * 0.5;
       
       gl_Position = pos;      
       vec4 col = gl_Color;
        col.x = 0.0;
       col.y = 1.0;
       col.z = 1.0;
       gl_FrontColor = col;

}