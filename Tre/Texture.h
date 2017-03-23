#pragma once
#include "Common.h"

class Texture
{
public:
	Texture(const std::string& fileName);
	~Texture();

	GLuint GetHandler() { return textureHandler; }
	std::string path;

protected:
private:

	GLuint textureHandler;
};

