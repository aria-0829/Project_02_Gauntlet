#include "EngineCore.h"

Scene* Scene::instance = nullptr;

void Scene::Initialize()
{
	for (auto& entity : entities)
	{
		entity->Initialize();
	}
}

void Scene::Update()
{
	for (auto& entity : entities)
	{
		entity->Update();
	}

	CheckCollisions();
}

void Scene::Render()
{
	for (auto& entity : entities)
	{
		std::string name = entity->GetName();
		//std::cout << "Scene::Render: " << name << std::endl;
		entity->Render();
	}
}

void Scene::Destroy()
{
	for (auto& entity : entities)
	{
		entity->Destroy();
		delete entity;
	}
	entities.clear();
}

void Scene::Load(json::JSON& _json)
{
	if (_json.hasKey("Game"))
	{
		json::JSON gameData = _json["Game"];

		if (gameData.hasKey("scenefile"))
		{
			std::string scenefile = gameData["scenefile"].ToString();

			std::ifstream inputStream(scenefile);
			std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
			json::JSON sceneData = json::JSON::Load(str);

			if (sceneData.hasKey("Entities"))
			{
				json::JSON entitiesJSON = sceneData["Entities"];
				for (json::JSON& entityJSON : entitiesJSON.ArrayRange())
				{
					std::string entityName = entityJSON["ClassName"].ToString();
					std::cout << "Creating: " << entityName << std::endl;
					Entity* entity = CreateEntity(entityName);
					entity->SetName(entityName);
					entity->Load(entityJSON["ClassData"]);
				}
			}
		}
	}
}

Entity* Scene::CreateEntity(const std::string& _entityName)
{
	const auto entity = (Entity*)CreateObject(_entityName.c_str());
	//entity->ownerScene = this;
	entities.push_back(entity);
	std::cout << "Scene Created Entity" << std::endl;

	return entity;
}

Entity* Scene::GetEntityByName(std::string _entityName)
{
	for (auto& entity : entities)
	{
		if (entity->GetName() == _entityName)
		{
			return entity;
		}
	}

	std::cout << "EntityByName not found" << std::endl;
	return nullptr;
}

void Scene::AddEntity(Entity* _entity)
{
	entities.push_back(_entity);
	//RenderSystem::Instance().AddIRenderable(_entity);
	std::cout << "Added entity" << std::endl;
}

void Scene::CheckCollisions()
{
	//std::list<Projectile*> projectilesToRemove;

	////Iterate over projectiles of player
	//for (const auto& projectile : player->GetProjectiles())
	//{
	//	//Iterate over enemyUFO of enemySpawner
	//	for (const auto& enemyUFO : enemySpawner->GetUFOs())
	//	{
	//		if (CollisionDetection::Instance().CheckCollision(projectile->GetCollisionCircle(), enemyUFO->GetCollisionCircle()))
	//		{
	//			enemySpawner->RemoveUFO(enemyUFO);
	//			enemyUFO->Destroy();
	//			delete enemyUFO;

	//			player->RemoveProjectile(projectile);
	//			projectile->Destroy();
	//			delete projectile;
	//		}
	//	}

	//	//Iterate over enemyShip of enemySpawner
	//	for (const auto& enemyShip : enemySpawner->GetShips())
	//	{
	//		if (CollisionDetection::Instance().CheckCollision(projectile->GetCollisionCircle(), enemyShip->GetCollisionCircle()))
	//		{
	//			enemySpawner->RemoveShip(enemyShip);
	//			enemyShip->Destroy();
	//			delete enemyShip;

	//			player->RemoveProjectile(projectile);
	//			projectile->Destroy();
	//			delete projectile;
	//		}
	//	}
	//}
	//for (auto projectile : projectilesToRemove)
	//{
	//	player->RemoveProjectile(projectile);
	//	delete projectile;
	//}
}
