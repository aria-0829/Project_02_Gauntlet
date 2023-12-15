#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Skeleton)

void Skeleton::Update()
{
	Entity::Update();

	dstrect.y += speed;

	static int frameCount = 0;
	const int spawnInterval = 20;

	if (frameCount % spawnInterval == 0)
	{
		EnemyProjectile* projectile = new EnemyProjectile();
		enemyProjectiles.push_back(projectile);
		projectile->Load(enemyProjectileData);
		projectile->SetPositionX(dstrect.x + imageWidth / 2);
		projectile->SetPositionY(dstrect.y + imageHeight);
		projectile->Initialize();
	}

	++frameCount;

	enemyProjectiles.remove_if([](EnemyProjectile* projectile)
		{
			projectile->Update();
			//projectile->Render();

			//Check if the projectile is out of the window
			if (projectile->GetPositionY() < 0)
			{
				projectile->Destroy();
				delete projectile;
				return true; //Remove the projectile
			}

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
			return false; //Keep the projectile
		});
}

void Skeleton::Render()
{
	Entity::Render();

	for (auto projectile : enemyProjectiles)
	{
		projectile->Render();
	}
}

void Skeleton::Destroy()
{
	for (auto projectile : enemyProjectiles)
	{
		projectile->Destroy();
		delete projectile;
	}
	enemyProjectiles.clear();

	Entity::Destroy();
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

	if (_json.hasKey("EnemyProjectile"))
	{
		enemyProjectileData = _json["EnemyProjectile"];  //Load the player projectile data
	}
	
}
