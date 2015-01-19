#include "GameEngine.h"
#include <iostream>
/*!
 * \class GameEngine.cpp
 *
 * \brief : Its a Component based engine.
 * Game Engine class handles different system.
 * Systems can be Physics, GraphicsSystem, Window, etc.
 * Each system in turn handles components like Physics will handle
 * component like Body.
 * \author Akshay
 */
GameEngine *GameEngine::pEngine = NULL;

/*!
 * GetEngine
 * \brief :Method is responsible for returning the single instance of engine.
 * \return GameEngine*
 */
GameEngine* GameEngine::GetEngine()
{
	if(!pEngine)
	{
		pEngine = new GameEngine();
	}
	return pEngine;
}

GameEngine::GameEngine() : running(true)
{
}

GameEngine::~GameEngine()
{
	//destroy all the systems from the system list.
	systemList.erase(systemList.begin(),systemList.end());
}

/*!
 * Initialize
 * \brief :Method is responsible for initializing all the systems.
 * \return void
 */
void GameEngine::Initialize() 
{
	for (unsigned i = 0; i < systemList.size(); ++i)
		systemList[i]->Init();
}

/*!
 * AddEngineSystem
 * \brief :Method is responsible for adding a system to engine.
 * \param[in] IGameEngine * system
 * \return void
 */
void GameEngine::AddEngineSystem(IGameEngine *system) 
{
	systemList.push_back(system);
}

/*!
 * SendBroadCastMsg
 * \brief :Method is responsible for sending broadcast to all the systems.
 * \param[in] Msg msg
 * \return void
 */
void GameEngine::SendBroadCastMsg(Msg msg)
{
	if(msg.type == msg.msg_quit)
	{
		running = false;
	}
	else {
		//send msg to all the systems
		for (unsigned i = 0; i < systemList.size(); ++i)
			systemList[i]->OnMsgEvent(msg);
	}
}

/*!
 * MainLoop
 * \brief :Method is responsible for handing game main loop.
 * \return void
 */
void GameEngine::MainLoop() 
{
	while(running) {
		for (unsigned i = 0; i < systemList.size(); ++i) {
			systemList[i]->Update(1);
		}
	}
}