#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GameEngine.h"

class WindowSystem : public IGameEngine
{
public:
	WindowSystem(unsigned int width, unsigned int height);
	~WindowSystem();
	virtual void Init(); //came from IGameEngine
	virtual void Update(float deltaTime); //came from IGameEngine
	GLFWwindow* GetWindow() { return window; }
private:
	GLFWwindow* window;
	unsigned int window_width;
	unsigned int window_height;
};