#include "GameCore.h"

Background::Background()
{
	std::cout << "Background Created" << std::endl;
}

Background::~Background()
{
	std::cout << "Background Deleted" << std::endl;
}

void Background::Initialize(int posY)
{
	int windowWidth = RenderSystem::Instance().GetWidth();
	int windowHeight = RenderSystem::Instance().GetHeight();

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	
	dstrect = { 0, posY, windowWidth, windowHeight }; //Background starting position
}

void Background::Update()
{
	//Move back again when out of window
	dstrect.y += scrollSpeed;
	if (dstrect.y >= RenderSystem::Instance().GetHeight())
	{
		dstrect.y = -RenderSystem::Instance().GetHeight();
	}
}

void Background::Destroy()
{
}

void Background::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Background::Load(json::JSON& _json)
{
	if (_json.hasKey("Background"))
	{
		json::JSON backgroundSettings = _json["Background"];

		if (backgroundSettings.hasKey("scrollSpeed"))
		{
			scrollSpeed = backgroundSettings["scrollSpeed"].ToInt(); //Load scroll speed
		}

		if (backgroundSettings.hasKey("imagePath"))
		{
			imagePath = backgroundSettings["imagePath"].ToString(); //Load image path
		}
	}
}
