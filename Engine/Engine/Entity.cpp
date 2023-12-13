#include "EngineCore.h"

void Entity::Initialize() 
{
	Object::Initialize();

	for (const auto& c: components) 
	{
		c->Initialize();
	}
}

void Entity::Update() 
{
	for (const auto& c: components) 
	{
		c->Update();
	}
}

void Entity::Destroy() 
{
	for (auto& c: components) 
	{
		c->Destroy();
		delete c;
	}
	components.clear();

	Object::Destroy();
}

void Entity::Load(const json::JSON& entityNode) 
{
	Object::Load(entityNode);

	// TODO: Implement Entity loading
}

Component* Entity::CreateComponent(std::string _componentType) 
{
	Component* component = nullptr;

	// Component Creation is not currently implemented
	_ASSERT(component != nullptr);
	component->entity = this;

	return component;
}

void Entity::RemoveComponent(Component* _component) 
{
	// Remove the Component from the list of Components.
	components.remove(_component);

	// Reset the Component's entity, if we're the Entity currently set.
	if (_component->entity == this) 
	{
		_component->entity = nullptr;
	}
}