#version 330

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoord0;

uniform mat4 transform;
uniform vec3 camPos;
uniform mat4 viewProj;

out vec4 v_pos;
out vec3 v_norm;
out vec3 cam;
out mat4 trans;
out mat4 view;

void main()
{
	cam = camPos;
	gl_Position = transform * vec4(position, 1.0);
	trans = transform;
	view = viewProj;
	v_pos = transform * vec4(position, 1.0);;
	v_norm = normal;
	texCoord0 = texCoord;
}