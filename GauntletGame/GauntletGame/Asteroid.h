#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "Entity.h"
#include "IRenderable.h"

class Asteroid : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Asteroid, Entity)

public:
	Asteroid() = default;
	~Asteroid() override = default;

	void Initialize();
	void Update();
	void Load(json::JSON& _json);
};
#endif // !_ASTEROID_H_


