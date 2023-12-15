#pragma once
#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "Entity.h"
#include "IRenderable.h"

class Skeleton : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Skeleton, Entity)

private:
	int direction = 0;

public:
	Skeleton() = default;
	~Skeleton() override = default;

	void Initialize();
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_SKELETON_H_


