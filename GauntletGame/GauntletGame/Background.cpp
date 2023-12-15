#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Background);

void Background::Initialize()
{
	int windowWidth = RenderSystem::Instance().GetWidth();
	int windowHeight = RenderSystem::Instance().GetHeight();

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	
	dstrect = { 0, 0, windowWidth, windowHeight }; //Background starting position
	std::cout << "Background Initialized" << std::endl << std::endl;
}

void Background::Update()
{
	//Move back again when out of window
	dstrect.y += speed;
	if (dstrect.y >= RenderSystem::Instance().GetHeight())
	{
		dstrect.y = -RenderSystem::Instance().GetHeight();
	}
}

void Background::Load(json::JSON& _json)
{
	if (_json.hasKey("speed"))
	{
		speed = _json["speed"].ToInt(); //Load scroll speed
	}

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString(); //Load image path
	}
	
}
