#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(EnemyProjectile)

void EnemyProjectile::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;

	Vector2D playerPos = Scene::Instance().GetEntityByName("Player")->GetPosition();
	direction = Vector2D(playerPos - position);
	direction.Normalize();
	std::cout << "Ghost shooting at Direction: " << direction.x << ", " << direction.y << std::endl;
}

void EnemyProjectile::Update()
{
	Entity::Update();

	float deltaTime = GameTime::Instance().DeltaTime();
	position = direction * speed * deltaTime + position;
}

void EnemyProjectile::Load(json::JSON& _json)
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
