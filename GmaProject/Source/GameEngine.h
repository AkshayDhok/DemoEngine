#pragma once
#include "IGameEngine.h" // core engine interface
#include <vector>
/*!
 * \file GameEngine.h
 * \author Akshay
 */
class GameEngine
{
public:
	static GameEngine* GetEngine();
	~GameEngine();

	void Initialize();
	void AddEngineSystem(IGameEngine *system);
	void MainLoop();

	// Sends broadcast msg to all the sub systems
	// This is called through a global pointer to GameEngine.
	void SendBroadCastMsg(Msg);

private:
	//singleton pattern
	GameEngine();
	// pointer to engine to send broadcast to engine from system.
	static GameEngine *pEngine;

	// list of all the system that engine handles ex: physics, graphics,etc.
	std::vector<IGameEngine*> systemList;
	// flag to control game loop
	bool running;
	
};

