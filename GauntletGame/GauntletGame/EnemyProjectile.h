#pragma once
#ifndef _ENEMY_PROJECTILE_H_
#define _ENEMY_PROJECTILE_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyProjectile : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemyProjectile, Entity)

private:
	Vector2D direction;
	
public:
	EnemyProjectile() = default;
	~EnemyProjectile() override = default;

	void Initialize() override;
	void Update() override;
	void Load(json::JSON& _json) override;
};

#endif // !_ENEMY_PROJECTILE_H_
