#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM\glm.hpp>
#include "Message.h"
#include "GameEngine.h"
#include "Sprite.h"

/*!
 * \class Graphics.h
 *
 * \brief : Class responsible for drawing everything on screen through opengl.
 * Graphics system is updated every frame and it draws all the game objects.
 * It also handles when to show debug draw.
 * \author Akshay
 */

class Graphics : public IGameEngine
{
public :
	static Graphics* getGraphics();
	virtual ~Graphics();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void OnMsgEvent(Msg msg);

	void setWindow(GLFWwindow *);

private:
	//private constructor
	Graphics();


	GLFWwindow* pWindow;
	std::vector<Sprite*> spriteArray;
	//pointer to singleton instance of the Graphics system.
	static Graphics* pGraphics;
};

