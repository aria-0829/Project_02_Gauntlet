#pragma once
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Entity.h"
#include "IRenderable.h"

class Projectile : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Projectile, Entity)

private:
	Vector2D direction;
	float speed = 0.0f;

public:
	Projectile() = default;
	~Projectile() override = default;

	void Initialize() override;
	void Update() override;
	void Load(json::JSON& _json);
};

#endif // !_PROJECTILE_H_

