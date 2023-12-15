#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Barrel)

void Barrel::Initialize()
{
	Entity::Initialize();

	//Generate a random scale
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> scaleDis(0.5f, 1.5f);
	float scale = scaleDis(gen);

	//Generate a random start position
	std::uniform_real_distribution<float> posDis(0, RenderSystem::Instance().GetWidth());

	position.x = posDis(gen);
	position.y = -imageHeight;
	dstrect.w = static_cast<int>(imageWidth * scale);
	dstrect.h = static_cast<int>(imageHeight * scale);
}

void Barrel::Update()
{
	Entity::Update();
}

void Barrel::Render()
{
	Entity::Render();
}

void Barrel::Load(json::JSON& _json)
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
