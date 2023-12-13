#include "EngineCore.h"

void Object::Initialize() 
{
	initialized = true;
}

void Object::Destroy() 
{

}

void Object::Load(const json::JSON& objectNode) 
{
	if (objectNode.hasKey("name")) 
	{
		name = objectNode.at("name").ToString();
	}
	if (objectNode.hasKey("id")) 
	{
		id = objectNode.at("id").ToInt();
	}
}
