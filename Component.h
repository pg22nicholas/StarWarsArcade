#pragma once

enum class ComponentTypes
{
	Empty,
	Transform,
	Physics,
	Box,
	Circle,
	Controller
};

class GameObject;

class Component
{
public:

	Component(GameObject* Owner);
	~Component();

	virtual void Initialize();
	virtual void Destroy();
	virtual ComponentTypes GetType();
	GameObject* GetGameObject();


protected:

	GameObject* mOwningGameObject;
};

