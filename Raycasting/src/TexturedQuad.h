#pragma once

#include <vector>
#include <vector>
#include <array>
#include "Texture.h"
#include "OpenglBufferObjects.h"
#include "Shader.h"

// Represents rectangular area with a subsection of a texture stretched over it
class TexturedQuad {
public:
	// every quad requires a texture reference, the texture itself must be managed elsewhere
	// by default the entire texture is stretched over the quad, use setTextureSampleArea() to specify which part of the texture to render
	TexturedQuad(float x, float y, float width, float height, Texture& texture);

	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setBounding(float x, float y, float width, float height);
	void setTexture(Texture& texture);

	// specify what part of the texture will be rendered over the quad
	// bottom left of texture is (0, 0), top right is (1, 1)
	void setTextureSampleArea(float x, float y, float width, float height);

	void render();

private:
	Texture* tex;
	float x, y, width, height;
	float texX = 0, texY = 0, texWidth = 1, texHeight = 1;
};