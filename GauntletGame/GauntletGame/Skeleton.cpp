#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Skeleton)

void Skeleton::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;
}

void Skeleton::Update()
{
	Entity::Update();

	// Goto player position
	Vector2D playerPos = Scene::Instance().GetEntityByName("Player")->GetPosition();
	Vector2D direction = Vector2D(playerPos - position);
	direction.Normalize();

	float deltaTime = GameTime::Instance().DeltaTime();
	position = direction * speed * deltaTime + position;
}

void Skeleton::Load(json::JSON& _json)
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
