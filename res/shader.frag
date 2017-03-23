#version 120

varying vec2 texCoord0;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;
uniform sampler2D texture_specular1;
uniform sampler2D texture_specular2;


void main()
{
	gl_FragColor = 0.6f + texture2D(texture_diffuse1, texCoord0);
}
