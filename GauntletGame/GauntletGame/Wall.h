#pragma once
#ifndef _WALL_H_
#define _WALL_H_

#include "Entity.h"
#include "IRenderable.h"

class Wall : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Wall, Entity)

public:
	Wall() = default;
	~Wall() override = default;

	void Initialize();
	void Update();
	void Render();
	void Load(json::JSON& _json);
};

#endif // !_WALL_H_
