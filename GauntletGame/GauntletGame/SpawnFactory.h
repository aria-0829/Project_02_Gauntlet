#pragma once
#ifndef _SPAWN_FACTORY_H_
#define _SPAWN_FACTORY_H_

#include "Entity.h"
#include "IRenderable.h"

class SpawnFactory : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(SpawnFactory, Entity)

private:
	int spawnInterval = 0;
	float timeCounter = 0.0f;
	std::list<Entity*> spawnedList;

	json::JSON spawnData;
	std::string spawnName;

public:
	SpawnFactory() = default;
	~SpawnFactory() override = default;

	void Initialize();
	void Update();
	void Spawn();

	void Load(json::JSON& _json);
};
#endif // !_SPAWN_FACTORY_H_
