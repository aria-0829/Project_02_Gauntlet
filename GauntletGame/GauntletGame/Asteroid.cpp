#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Asteroid)

void Asteroid::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex

	//Generate a random scale
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> scaleDis(0.5f, 1.5f);
	float scale = scaleDis(gen);

	//Generate a random start position
	std::uniform_real_distribution<float> posDis(0, RenderSystem::Instance().GetWidth());
	int posX = posDis(gen);

	dstrect = { posX, -imageHeight, static_cast<int>(imageWidth * scale), static_cast<int>(imageHeight * scale) };  //Coming from top
}

void Asteroid::Update()
{
	Entity::Update();

	dstrect.y += speed; //Move down
}

void Asteroid::Load(json::JSON& _json)
{
	if (_json.hasKey("speed"))
	{
		speed = _json["speed"].ToInt();  //Load speed
	}

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
