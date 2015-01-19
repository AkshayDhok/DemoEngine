#pragma once
/*!
 * \class ObjectComponent.h
 * \brief : Base class for all the components.
 * \author Akshay
 */
//forward deceleration
class GameObject;

class ObjectComponent
{
public:

	virtual void Initialize(){};

	/************************************************************************/
	/* Returns the base object of component.                                */
	/************************************************************************/
	GameObject* getGameObject(){ return pBase; }

	virtual ~ObjectComponent(){};

	GameObject *pBase;
};