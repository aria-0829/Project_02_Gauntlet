#pragma once
#ifndef _GHOST_H_
#define _GHOST_H_

#include "Entity.h"
#include "IRenderable.h"

class Ghost : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Ghost, Entity)

private:
	int direction = 0;

public:
	Ghost() = default;
	~Ghost() override = default;

	void Update();
	void Load(json::JSON& _json);
};

#endif // !_GHOST_H_


