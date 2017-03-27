#version 330

layout( location = 0 ) out vec4 fragcolor;
 
in vec3 v_norm;
in vec4 v_pos; 
in vec3 cam;
in mat4 trans;
in mat4 view;

varying vec2 texCoord0;

uniform sampler2D diffuse_texture1;
uniform sampler2D diffuse_texture2;
 
void main()
{
  //mat4 Normal = mat3(transpose(inverse(model))) * normal;

  //vector back to camera
  vec3 p = vec3(cam - v_pos.xyz);			// position in view space
  vec3 v = normalize(-p);                       // eye vector

  vec3 n = normalize(mat3(view) * v_norm);      // convert normal to view space, u_vm (view matrix), is a rigid body transform.
  
  float vdn = 1.0 - max(dot(n, v), 0.0);        // the rim contribution 1.0 -
 
  fragcolor.a = 1.0;
  //(texture2D(diffuse_texture1, texCoord0) * 
  fragcolor.rgb = vec3(smoothstep(0.0, 1.0, vdn));
}