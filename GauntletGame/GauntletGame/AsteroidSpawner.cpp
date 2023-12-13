#include "GameCore.h"

AsteroidSpawner::AsteroidSpawner()
{
	std::cout << "Asteroid Spawner Created" << std::endl;
}

AsteroidSpawner::~AsteroidSpawner()
{
	std::cout << "Asteroid Spawner Deleted" << std::endl;
}

void AsteroidSpawner::Update()
{
	SpawnAsteroids();

	//Update and render asteroids, destroy when necessary
	asteroids.remove_if([](Asteroid* asteroid) 
	{
		asteroid->Update();
		asteroid->Render();

		//Check if the asteroid is out of the window
		if (asteroid->GetPositionY() > RenderSystem::Instance().GetHeight())
		{
			asteroid->Destroy();
			delete asteroid;
			return true; //Remove the asteroid
		}

		//Get the collision circles
		Circle asteroidCollider = asteroid->GetCollisionCircle();
		Circle playerCollider = Game::Instance().GetPlayer()->GetCollisionCircle();

		//Check if the asteroid collides with the player
		if (CollisionDetection::Instance().CheckCollision(playerCollider, asteroidCollider))
		{
			Game::Instance().GetPlayer()->Damaged();
			asteroid->Destroy();
			delete asteroid;
			return true; //Remove the asteroid
		}

		//Check if the asteroid collides with the player's projectiles
		for (const auto& projectile : Game::Instance().GetPlayer()->GetProjectiles())
		{
			if (CollisionDetection::Instance().CheckCollision(projectile->GetCollisionCircle(), asteroidCollider))
			{
				Game::Instance().GetPlayer()->RemoveProjectile(projectile);
				projectile->Destroy();
				delete projectile; //Remove the projectile

				asteroid->Destroy();
				delete asteroid;
				return true; //Remove the asteroid
			}
		}

		return false; //Keep the asteroid
	});

	SpawnStars();

	//Update and render stars
	stars.remove_if([](Star* star)
		{
			star->Update();
			star->Render();

			//Check if the star is out of the window
			if (star->GetPositionY() > RenderSystem::Instance().GetHeight())
			{
				star->Destroy();
				delete star;
				return true; //Remove the star
			}
			return false; //Keep the star
		});

}

void AsteroidSpawner::Destroy()
{
	//Destroy asteroids
	for (auto asteroid : asteroids)
	{
		asteroid->Destroy();
		delete asteroid;
	}
	asteroids.clear();

	//Destroy stars
	for (auto star : stars)
	{
		star->Destroy();
		delete star;
	}
	stars.clear();
}

void AsteroidSpawner::SpawnAsteroids()
{
	static int frameCount = 0;
	const int spawnInterval = 80;

	if (frameCount % spawnInterval == 0)
	{
		Asteroid* asteroid = new Asteroid();
		AddAsteroid(asteroid);
		asteroid->Load(asteroidData);
		asteroid->Initialize();
	}

	++frameCount;
}

void AsteroidSpawner::AddAsteroid(Asteroid* _asteroid)
{
	asteroids.push_back(_asteroid);
}

void AsteroidSpawner::SpawnStars()
{
	static int frameCount = 0;
	const int spawnInterval = 30;

	if (frameCount % spawnInterval == 0)
	{
		Star* star = new Star();
		stars.push_back(star);
		star->Load(starData);
		star->Initialize();
	}

	++frameCount;
}

void AsteroidSpawner::Load()
{
	std::ifstream inputStream("../Data/Asteroid.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	//std::cout << documentData.dump() << std::endl;

	if (documentData.hasKey("Asteroid"))
	{
		asteroidData = documentData["Asteroid"];
	}

	std::ifstream inputStreamStar("../Data/Star.json");
	std::string strStar((std::istreambuf_iterator<char>(inputStreamStar)), std::istreambuf_iterator<char>());
	json::JSON documentDataStar = json::JSON::Load(strStar);

	if (documentDataStar.hasKey("Star"))
	{
		starData = documentDataStar["Star"];
	}
}

