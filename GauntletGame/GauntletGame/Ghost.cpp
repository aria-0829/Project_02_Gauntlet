#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Ghost)

void Ghost::Update()
{
	Entity::Update();

	if (direction == 1)
	{
		//Moving from left to right
		dstrect.x += speed;
	}
	else
	{
		//Moving from right to left
		dstrect.x -= speed;
	}

	//Change direction if ufo is out of window
	if (dstrect.x > RenderSystem::Instance().GetWidth() || dstrect.x < -imageWidth)
	{
		direction *= -1;
	}
}

void Ghost::Load(json::JSON& _json)
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
