#pragma once
#include "Common.h"

class Texture
{
public:
	Texture();
	~Texture();

	GLuint GetHandler() { return textureHandler; }
	void SetHandler(GLuint handler) { textureHandler = handler; }
	std::string path, type;

protected:
private:

	GLuint textureHandler;
};

