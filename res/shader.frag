#version 120

varying vec2 texCoord0;

uniform sampler2D texture_diffuse1;

void main()
{
	gl_FragColor = texture2D(texture_diffuse1, texCoord0);
}
