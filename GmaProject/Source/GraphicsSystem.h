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
 * \class GraphicsSystem.h
 *
 * \brief : Class responsible for drawing everything on screen through opengl.
 * GraphicsSystem system is updated every frame and it draws all the game objects.
 * It also handles when to show debug draw.
 * \author Akshay
 */

class GraphicsSystem : public IGameEngine
{
public :
	static GraphicsSystem* getGraphics();
	virtual ~GraphicsSystem();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void OnMsgEvent(Msg msg);

	void setWindow(GLFWwindow *);

private:
	//private constructor
	GraphicsSystem();


	GLFWwindow* pWindow;
	std::vector<Sprite*> spriteArray;
	//pointer to singleton instance of the GraphicsSystem system.
	static GraphicsSystem* pGraphics;
};

