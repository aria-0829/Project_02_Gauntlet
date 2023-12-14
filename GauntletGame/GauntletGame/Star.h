#pragma once
#ifndef _STAR_H_
#define _STAR_H_

#include "Entity.h"
#include "IRenderable.h"

class Star : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Star, Entity)

public:
	Star() = default;
	~Star() override = default;

	void Initialize();
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_STAR_H_
