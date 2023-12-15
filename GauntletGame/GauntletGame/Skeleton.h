#pragma once
#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyProjectile;
class Circle;

class Skeleton : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Skeleton, Entity)

private:
	std::list<EnemyProjectile*> enemyProjectiles;
	json::JSON enemyProjectileData;

public:

	Skeleton() = default;
	~Skeleton() override = default;

	void Update();
	void Render();
	void Destroy();
	void Load(json::JSON& _json);
};
#endif // !_SKELETON_H_



