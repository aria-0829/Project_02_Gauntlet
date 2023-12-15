#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Wall)

void Wall::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;
}

void Wall::Update()
{
	Entity::Update();
}

void Wall::Render()
{
	Entity::Render();
}

void Wall::Load(json::JSON& _json)
{
	Entity::Load(_json);

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString();  //Load image path
	}

	if (_json.hasKey("imageWidth"))
	{
		imageWidth = _json["imageWidth"].ToInt();  //Load image width
	}

	if (_json.hasKey("imageHeight"))
	{
		imageHeight = _json["imageHeight"].ToInt();  //Load image height
	}
}
