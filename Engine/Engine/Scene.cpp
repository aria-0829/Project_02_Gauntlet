#include "EngineCore.h"

void Scene::Initialize() 
{
	for (const auto& e: entities) 
	{
		e->Initialize();
	}
}

void Scene::Destroy() 
{
	for (const auto& e: entities) 
	{
		e->Destroy();
		delete e;
	}
	entities.clear();
}

void Scene::Update() 
{
	for (const auto& e: entities) 
	{
		e->Update();
	}
}

void Scene::Load(json::JSON& _json)
{
	/*for (auto& componentData : _json.ArrayRange())
	{
		Component* component = new Component();
		AddComponent(component);
		component->Load(componentData);
	}*/
	if (_json.hasKey("Player"))
	{
		json::JSON playerData = _json["Player"];

		//player = new Player();
		//player->Load(playerData);
		std::cout << playerData.dump() << std::endl << std::endl;
	}
	if (_json.hasKey("Background"))
	{
		json::JSON backgroundData = _json["Background"];

		/*background1 = new Background();
		background1->Load(backgroundData);
		background2 = new Background();
		background2->Load(backgroundData);*/
	}
}

Entity* Scene::CreateEntity() 
{
	const auto entity = new Entity();
	entities.push_back(entity);

	return entity;
}

void Scene::RemoveEntity(Entity* _entity) 
{
	entities.remove(_entity);
}

Entity* Scene::FindEntityById(int id) 
{
	// TODO: Implement Finding Entities
	return nullptr;
}