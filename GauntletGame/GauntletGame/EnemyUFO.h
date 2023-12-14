#pragma once
#ifndef _ENEMY_UFO_H_
#define _ENEMY_UFO_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyUFO : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemyUFO, Entity)

private:
	int direction = 0;

public:
	EnemyUFO() = default;
	~EnemyUFO() override = default;

	void Initialize();
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_ENEMY_UFO_H_


