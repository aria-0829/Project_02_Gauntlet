#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Projectile)

void Projectile::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;
}

void Projectile::Update()
{
	Entity::Update();
	position.y -= speed;
	//position = direction * speed + position;
	//dstrect.y += direction.y * speed;

	//std::cout << "Projectile: " << position.x << ", " << position.y << std::endl;
	//std::cout << "Dstrect: " << dstrect.x << ", " << dstrect.y << std::endl;
}

void Projectile::Load(json::JSON& _json)
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
