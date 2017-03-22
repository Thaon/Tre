#pragma once
#include "Common.h"

class Texture
{
public:
	Texture(const std::string& fileName);

	GLuint GetHandler() { return textureHandler; }
	~Texture();

protected:
private:

	GLuint textureHandler;
};

