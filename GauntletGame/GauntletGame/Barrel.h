#pragma once
#ifndef _BARREL_H_
#define _BARREL_H_

#include "Entity.h"
#include "IRenderable.h"

class Barrel : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Barrel, Entity)

public:
	Barrel() = default;
	~Barrel() override = default;

	void Initialize();
	void Update();
	void Render();
	void Load(json::JSON& _json);
};
#endif // !_BARREL_H_


