#include "GameCore.h"

Game* Game::instance = nullptr;

void Game::Initialize()
{
	int height = RenderSystem::Instance().GetHeight();
	background1->Initialize(0);
	background2->Initialize(-height);
	player->Initialize();
}

void Game::Update()
{
	background1->Update();
	background1->Render();
	background2->Update();
	background2->Render();

	asteroidSpawner->Update();

	player->Update();

	enemySpawner->Update();

	CheckCollisions();
}

void Game::Destroy()
{
	//Destroy enemySpawner
	enemySpawner->Destroy();
	delete enemySpawner;

	//Destroy player
	player->Destroy();
	delete player;

	//Destroy background
	background1->Destroy();
	delete background1;
	background2->Destroy();
	delete background2;

	//Destroy asteroidSpawner
	asteroidSpawner->Destroy();
	delete asteroidSpawner;

	//Destroy UI
	ui->Destroy();
	delete ui;
}

void Game::Load(json::JSON& _json)
{
	if (_json.hasKey("scenefile")) 
	{
		std::string scenefile = _json["scenefile"].ToString();

		std::ifstream inputStream(scenefile);
		std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
		json::JSON sceneData = json::JSON::Load(str);

		background1 = new Background();
		background1->Load(sceneData);
		background2 = new Background();
		background2->Load(sceneData);

		player = new Player();
		player->Load(sceneData);
	}

	asteroidSpawner = new AsteroidSpawner();
	asteroidSpawner->Load();

	enemySpawner = new EnemySpawner();
	enemySpawner->Load();

	ui = new UI();
}

void Game::CheckCollisions()
{
	std::list<Projectile*> projectilesToRemove;

	//Iterate over projectiles of player
	for (const auto& projectile : player->GetProjectiles())
	{
		//Iterate over enemyUFO of enemySpawner
		for (const auto& enemyUFO : enemySpawner->GetUFOs())
		{
			if (CollisionDetection::Instance().CheckCollision(projectile->GetCollisionCircle(), enemyUFO->GetCollisionCircle()))
			{
				enemySpawner->RemoveUFO(enemyUFO);
				enemyUFO->Destroy();
				delete enemyUFO;

				player->RemoveProjectile(projectile);
				projectile->Destroy();
				delete projectile;
			}
		}

		//Iterate over enemyShip of enemySpawner
		for (const auto& enemyShip : enemySpawner->GetShips())
		{
			if (CollisionDetection::Instance().CheckCollision(projectile->GetCollisionCircle(), enemyShip->GetCollisionCircle()))
			{
				enemySpawner->RemoveShip(enemyShip);
				enemyShip->Destroy();
				delete enemyShip;

				player->RemoveProjectile(projectile);
				projectile->Destroy();
				delete projectile;
			}
		}
	}
	for (auto projectile : projectilesToRemove)
	{
		player->RemoveProjectile(projectile);
		delete projectile;
	}
}

