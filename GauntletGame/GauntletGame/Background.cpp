#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Background);

void Background::Initialize()
{
	Entity::Initialize();

	dstrect.w = RenderSystem::Instance().GetWidth();
	dstrect.h = RenderSystem::Instance().GetHeight();
}

void Background::Load(json::JSON& _json)
{
	Entity::Load(_json);

	if (_json.hasKey("speed"))
	{
		speed = _json["speed"].ToInt(); //Load scroll speed
	}

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString(); //Load image path
	}
	
}
