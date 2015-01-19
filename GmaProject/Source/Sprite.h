#pragma once
#include "ObjectComponent.h"
#include <GL\glew.h>
/*!
 * \class Sprite.h
 *
 * \brief : Sprite is a component. If a game object have sprite
 * component , then that object will be displayed on screen.
 *
 * \author Akshay
 */

class Sprite : public ObjectComponent
{
public:
	/** Some object will be on foreground some on back. It represents z values.
	    FOREGROUND is used for parallelx ,
		BACKBROUND for background,
		all game objects are in ONGROUND level.*/
	enum DISPLAY_LAYERS {
		LEVEL_BACKGROUND = -3,
		LEVEL_ONGROUND = -2,
		LEVEL_FOREGROUND = -1
	};

	Sprite();
	~Sprite();

	virtual void Initialize();
	
	void Draw();
	
	float DISPLAY_LEVEL;

private:

	float *mVertexArray;
	float *mTextureArray;

	// buffers
	GLuint vertexbuffer;
	GLuint colorbuffer;

	int mVerticesCount;
};