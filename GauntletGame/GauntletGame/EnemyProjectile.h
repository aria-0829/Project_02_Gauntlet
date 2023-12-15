#pragma once
#ifndef _ENEMY_PROJECTILE_H_
#define _ENEMY_PROJECTILE_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyProjectile : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemyProjectile, Entity)

public:
	EnemyProjectile() = default;
	~EnemyProjectile() override = default;

	void Initialize() override;
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_ENEMY_PROJECTILE_H_
