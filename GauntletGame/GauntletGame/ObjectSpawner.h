#pragma once
#ifndef _OBJECT_SPAWNER_H_
#define _OBJECT_SPAWNER_H_

#include "Entity.h"
#include "IRenderable.h"

class Wall;
class Barrel;

class ObjectSpawner : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(ObjectSpawner, Entity)

private:
	std::list<Barrel*> barrels;
	json::JSON barrelData;
	std::list<Wall*> walls;
	json::JSON wallData;

public:
	ObjectSpawner() = default;
	~ObjectSpawner() override = default;

	void Initialize() override;
	void Update();
	void Render();
	void Destroy();
	void Load(json::JSON& _json);
};

#endif // !_OBJECT_SPAWNER_H_


