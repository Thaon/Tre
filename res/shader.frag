#version 120

varying vec2 texCoord0;

uniform sampler2D texture_diffuse2;

void main()
{
	gl_FragColor = texture2D(texture_diffuse2, texCoord0);
}
