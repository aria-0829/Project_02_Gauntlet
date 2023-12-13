#include "GameCore.h"

EnemyProjectile::EnemyProjectile()
{
	//std::cout << "EnemyProjectile Created" << std::endl;
}

EnemyProjectile::~EnemyProjectile()
{
	//std::cout << "EnemyProjectile Deleted" << std::endl;
}

void EnemyProjectile::Initialize(int posX, int posY)
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { posX, posY, imageWidth, imageHeight };
}

void EnemyProjectile::Update()
{
	dstrect.y += speed;

	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void EnemyProjectile::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void EnemyProjectile::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void EnemyProjectile::Load()
{
	std::ifstream inputStream("../Data/Projectile.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	if (documentData.hasKey("EnemyProjectile"))
	{
		json::JSON enemyProjectileData = documentData["EnemyProjectile"];

		if (enemyProjectileData.hasKey("speed"))
		{
			speed = enemyProjectileData["speed"].ToInt();  //Load speed
		}

		if (enemyProjectileData.hasKey("imagePath"))
		{
			imagePath = enemyProjectileData["imagePath"].ToString();  //Load image path
		}

		if (enemyProjectileData.hasKey("imageWidth"))
		{
			imageWidth = enemyProjectileData["imageWidth"].ToInt();  //Load image width
		}

		if (enemyProjectileData.hasKey("imageHeight"))
		{
			imageHeight = enemyProjectileData["imageHeight"].ToInt();  //Load image height
		}
	}
}
