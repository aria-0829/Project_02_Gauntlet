#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Ghost)

void Ghost::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;
}

void Ghost::Update()
{
	Entity::Update();

	// Goto player position
	Vector2D playerPos = Scene::Instance().GetEntityByName("Player")->GetPosition();
	Vector2D direction = Vector2D(playerPos - position);
	direction.Normalize();

	float deltaTime = GameTime::Instance().DeltaTime();
	position = direction * speed * deltaTime + position;

	// Shooting
	static int frameCount = 0;
	const int spawnInterval = 20;

	if (frameCount % spawnInterval == 0)
	{
		EnemyProjectile* projectile = new EnemyProjectile();
		enemyProjectiles.push_back(projectile);
		projectile->Load(enemyProjectileData);
		projectile->SetPositionX(position.x + imageWidth / 2);
		projectile->SetPositionY(position.y + imageHeight);
		projectile->Initialize();
	}

	++frameCount;

	//Update the projectiles
	for (auto projectile : enemyProjectiles)
	{
		projectile->Update();
	}
	
	//enemyProjectiles.remove_if([](EnemyProjectile* projectile)
	//	{
	//		projectile->Update();
	//		//projectile->Render();

	//		//Check if the projectile is out of the window
	//		if (projectile->GetPosition().y < 0)
	//		{
	//			projectile->Destroy();
	//			delete projectile;
	//			return true; //Remove the projectile
	//		}

	//		//Get the collision circles
	//		Circle projectileCollider = projectile->GetCollisionCircle();
	//		Circle playerCollider = Scene::Instance().GetPlayer()->GetCollisionCircle();

	//		//Check if the projectile collides with the player
	//		if (CollisionDetection::Instance().CheckCollision(playerCollider, projectileCollider))
	//		{
	//			Scene::Instance().GetPlayer()->Damaged();
	//			projectile->Destroy();
	//			delete projectile;
	//			return true; //Remove the projectile
	//		}
	//		return false; //Keep the projectile
	//	});
}

void Ghost::Render()
{
	Entity::Render();

	for (auto projectile : enemyProjectiles)
	{
		projectile->Render();
	}
}

void Ghost::Destroy()
{
	for (auto projectile : enemyProjectiles)
	{
		projectile->Destroy();
		delete projectile;
	}
	enemyProjectiles.clear();

	Entity::Destroy();
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

	if (_json.hasKey("EnemyProjectile"))
	{
		enemyProjectileData = _json["EnemyProjectile"];  //Load the player projectile data
	}
	
}
