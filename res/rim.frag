#version 330

layout( location = 0 ) out vec4 fragcolor;
 
in vec3 v_norm;
in vec4 v_pos; 
in mat4 cam;

varying vec2 texCoord0;

uniform sampler2D texture1;
uniform sampler2D texture2;
 
void main() {
 
  vec3 n = normalize(mat3(cam) * v_norm);      // convert normal to view space, u_vm (view matrix), is a rigid body transform.
  vec3 p = vec3(cam * v_pos);                   // position in view space
  vec3 v = normalize(-p);                       // eye vector
  float vdn = 1.0 - max(dot(v, n), 0.0);        // the rim contribution
 
  fragcolor.a = 1.0;
  fragcolor.rgb = (texture2D(texture2, texCoord0) * vec3(smoothstep(0.0, 0.6, vdn))) - (texture2D(texture1, texCoord0) * vec3(smoothstep(0.6, 1.0, vdn)));
}