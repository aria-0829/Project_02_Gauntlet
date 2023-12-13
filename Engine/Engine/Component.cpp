#include "EngineCore.h"

void Component::Initialize() 
{
	Object::Initialize();
}

void Component::Destroy() 
{
	Object::Destroy();
}

void Component::Load(const json::JSON& componenetNode) 
{
	Object::Load(componenetNode);
}
