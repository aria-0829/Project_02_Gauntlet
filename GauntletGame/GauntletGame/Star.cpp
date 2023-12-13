#include "GameCore.h"

Star::Star()
{
}

Star::~Star()
{
}

void Star::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	
	//Generate a random scale
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> scaleDis(0.5f, 2.0f);
	float scale = scaleDis(gen);

	//Generate a random start position
	std::uniform_real_distribution<float> posDis(0, RenderSystem::Instance().GetWidth());
	int posX = posDis(gen);

	dstrect = { posX, -imageHeight, static_cast<int>(imageWidth * scale), static_cast<int>(imageHeight * scale) };  //Coming from top

	//Generate a random speed
	std::uniform_real_distribution<float> speedDis(1.5, 3);
	speed = speedDis(gen);
}

void Star::Update()
{
	dstrect.y += speed; //Move down
}

void Star::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Star::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Star::Load(json::JSON& _json)
{
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
