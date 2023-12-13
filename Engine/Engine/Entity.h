#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Object.h"
class Component;
class Scene;

class Entity : public Object 
{
	friend class Scene;

private:
	std::list<Component*> components;
	//Transform transform;

protected:
	Entity() = default;
	~Entity() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update();

public:
	void Load(const json::JSON&) override;
	Component* CreateComponent(std::string _componentType);
	void RemoveComponent(Component* _component);

	//const Transform* GetTransform() { return &transform; }
};

#endif // !_ENTITY_H_