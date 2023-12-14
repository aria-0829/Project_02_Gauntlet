#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(EnemySpawner)

EnemySpawner::EnemySpawner()
{
	std::cout << "Enemy Spawner Created" << std::endl;
}

EnemySpawner::~EnemySpawner()
{
	std::cout << "Enemy Spawner Deleted" << std::endl;
}

void EnemySpawner::Initialize()
{
}

void EnemySpawner::Update()
{
	SpawnEnemies();

	//Update and render enemyShips, destroy when necessary
	ships.remove_if([](EnemyShip* ship)
	{
		ship->Update();
		ship->Render();

		//Check if the ship is out of the window
		if (ship->GetPositionY() > RenderSystem::Instance().GetHeight())
		{
			ship->Destroy();
			delete ship;
			return true; //Remove the ship
		}

	//	//Get the collision circles
	//	Circle shipCollider = ship->GetCollisionCircle();
	//	Circle playerCollider = Scene::Instance().GetPlayer()->GetCollisionCircle();

	//	//Check if the ship collides with the player
	//	if (CollisionDetection::Instance().CheckCollision(playerCollider, shipCollider))
	//	{
	//		Scene::Instance().GetPlayer()->Damaged();
	//		ship->Destroy();
	//		delete ship;
	//		return true; //Remove the ship
	//	}

		return false; //Keep the ship
	});

	//Update and render UFOs, destroy when necessary
	ufos.remove_if([](EnemyUFO* ufo)
		{
			ufo->Update();
			ufo->Render();

	//		//Get the collision circles
	//		Circle ufoCollider = ufo->GetCollisionCircle();
	//		Circle playerCollider = Scene::Instance().GetPlayer()->GetCollisionCircle();

	//		//Check if the ufo collides with the player
	//		if (CollisionDetection::Instance().CheckCollision(playerCollider, ufoCollider))
	//		{
	//			Scene::Instance().GetPlayer()->Damaged();
	//			ufo->Destroy();
	//			delete ufo;
	//			return true; //Remove the ufo
	//		}

	//		//Check if the ufo is out of the window
	//		//if (ufo->GetPositionY() > Renderer::Instance().GetHeight())
	//		//{
	//		//	ufo->Destroy();
	//		//	delete ufo;
	//		//	return true; //Remove the ufo
	//		//}
			return false; //Keep the ufo
		});
}

void EnemySpawner::SpawnEnemies()
{
	static int frameCount = 0;
	const int spawnInterval = 50;

	if (frameCount % spawnInterval == 0) 
	{
		// Spawn enemyShip
		EnemyShip* ship = new EnemyShip();
		AddShip(ship);
		ship->Load(enemiesData);
		ship->Initialize();

		// Spawn enemyUFO
		EnemyUFO* ufo = new EnemyUFO();
		AddUFO(ufo);
		ufo->Load(enemiesData);
		ufo->Initialize();
	}

	++frameCount;
}


void EnemySpawner::Destroy()
{
	for (auto& ship : ships)
	{
		ship->Destroy();
		delete ship;
	}
	ships.clear();

	for (auto& ufo : ufos)
	{
		ufo->Destroy();
		delete ufo;
	}
	ufos.clear();

}

void EnemySpawner::Load(json::JSON& _json)
{
	
	enemiesData = _json;
	
}

