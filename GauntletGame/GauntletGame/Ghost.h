#pragma once
#ifndef _GHOST_H_
#define _GHOST_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyProjectile;
class Circle;

class Ghost : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Ghost, Entity)

private:
	std::list<EnemyProjectile*> enemyProjectiles;
	json::JSON enemyProjectileData;

public:

	Ghost() = default;
	~Ghost() override = default;

	void Initialize();
	void Update();
	void Render();
	void Destroy();
	void Load(json::JSON& _json);
};
#endif // !_GHOST_H_



