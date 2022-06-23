#pragma once

enum class ComponentTypes
{
	Empty,
	Transform,
	Physics,
	Box,
	Circle,
	Text,
	Controller,
	Health,
	Attack
};

class GameObject;

class Component
{
public:

	Component(GameObject* Owner);
	~Component();

	virtual void Initialize();
	virtual void Update(float deltaTime) = 0;					
	virtual void Destroy();
	virtual ComponentTypes GetType();
	GameObject* GetGameObject();


protected:

	GameObject* mOwningGameObject;
};

