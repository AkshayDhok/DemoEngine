
#include "GameEngine.h"
#include "WindowSystem.h"
#include "GraphicsSystem.h"

/*!
* \class EngineMain.cpp
* \brief : This is the starting point of the program.
*  Here we create the game engine object and add the system
*  to the engine like graphics, windows etc.
* \author Akshay
* \date November 2014
*/
int main()
{
	GameEngine *engine = GameEngine::GetEngine();

	//create window system 
	WindowSystem *window = new WindowSystem(800, 600);

	//create graphics system
	GraphicsSystem *graphics_system = GraphicsSystem::getGraphics();
	graphics_system->setWindow(window->GetWindow());

	// add the systems to the engine.
	engine->AddEngineSystem(window);
	engine->AddEngineSystem(graphics_system);

	// initializes all the systems.
	engine->Initialize();

	//main game loop.
	engine->MainLoop();

	return 0;

}