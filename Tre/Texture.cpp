#include "Texture.h"
#include <cassert>
#include <iostream>

Texture::Texture()
{
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureHandler); // number of and address of textures
}