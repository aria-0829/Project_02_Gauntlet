#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Object.h"

class Entity : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Entity, Object)

protected:
	std::string name = "";
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };
	int posX = 0;
	int posY = 0;

public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void Initialize();
	virtual void Update();
	virtual void Destroy();
	virtual void Render();
	virtual void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	void SetPositionX(int _x) { posX = _x; }
	void SetPositionY(int _y) { posY = _y; }
	std::string GetName() { return name; }
	void SetName(std::string _name) { name = _name; }

	//Circle GetCollisionCircle() const { return collisionCircle; }
};

#endif // !_ENTITY_H_