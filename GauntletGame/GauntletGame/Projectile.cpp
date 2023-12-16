#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Projectile)

void Projectile::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;

	direction = RenderSystem::Instance().GetMousePosition() - position;
	std::cout << "Direction: " << direction.x << ", " << direction.y << std::endl;

	//direction.Normalize();
	std::cout << "Direction Normalized: " << direction.x << ", " << direction.y << std::endl;

}

void Projectile::Update()
{
	Entity::Update();

	float deltaTime = GameTime::Instance().DeltaTime();

	Vector2D temp = direction * speed * deltaTime + position;
	position = direction * speed * deltaTime + position;
	std::cout << "Projectile: " << position.x << ", " << position.y << std::endl;

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
