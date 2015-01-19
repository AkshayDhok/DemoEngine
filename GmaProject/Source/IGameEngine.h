#pragma once
#include "Message.h"
/*!
 * \class IGameEngine.h
 *
 * \brief : GameEngine Interface.
 *
 * \author Akshay
 */
class IGameEngine 
{
public:
	IGameEngine() {}
	virtual ~IGameEngine(){}

	virtual void Init()=0;
	virtual void Update(float deltaTime)=0;

	// receives events
	virtual void OnMsgEvent(Msg msg){};
};