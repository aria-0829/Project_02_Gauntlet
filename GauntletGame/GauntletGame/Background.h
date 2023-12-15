#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "Entity.h"
#include "IRenderable.h"

class Background : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Background, Entity)																			\

public:
	Background() = default;
	~Background() override = default;

	void Initialize() override;
	void Load(json::JSON& _json);
};

#endif // !_BACKGROUND_H_
