#pragma once
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Entity.h"
#include "IRenderable.h"

class Projectile : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Projectile, Entity)

public:
	Projectile() = default;
	~Projectile() override = default;

	void Initialize();
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_PROJECTILE_H_

