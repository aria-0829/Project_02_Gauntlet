#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(EnemyShip)

void EnemyShip::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex

	//Enemy start positiom at random of top
	int windowWidth = RenderSystem::Instance().GetWidth();
	dstrect = { 0, -imageHeight, imageWidth, imageHeight };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, (windowWidth - imageWidth));
	dstrect.x = dis(gen);
}

void EnemyShip::Update()
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

void EnemyShip::Render()
{
	Entity::Render();

	for (auto projectile : enemyProjectiles)
	{
		projectile->Render();
	}
}

void EnemyShip::Destroy()
{
	for (auto projectile : enemyProjectiles)
	{
		projectile->Destroy();
		delete projectile;
	}
	enemyProjectiles.clear();

	Entity::Destroy();
}

void EnemyShip::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyShip"))
	{
		json::JSON shipData = _json["EnemyShip"];

		if (shipData.hasKey("speed"))
		{
			speed = shipData["speed"].ToInt();  //Load speed
		}

		if (shipData.hasKey("imagePath"))
		{
			imagePath = shipData["imagePath"].ToString();  //Load image path
		}

		if (shipData.hasKey("imageWidth"))
		{
			imageWidth = shipData["imageWidth"].ToInt();  //Load image width
		}

		if (shipData.hasKey("imageHeight"))
		{
			imageHeight = shipData["imageHeight"].ToInt();  //Load image height
		}

		if (shipData.hasKey("EnemyProjectile"))
		{
			enemyProjectileData = shipData["EnemyProjectile"];  //Load the player projectile data
		}
	}
}
