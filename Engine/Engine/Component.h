#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"
class Entity;

class Component : public Object 
{
	friend class Entity;

protected:
	Entity* entity = nullptr;

	Component() = default;
	~Component() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update() = 0;

public:
	void Load(const json::JSON&) override;
};

#endif // !_COMPONENT_H_