#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Object.h"

class Entity : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Entity, Object)

protected:
	std::string name = "";
	Vector2D position;
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };

public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void Initialize();
	virtual void Update();
	virtual void Destroy();
	virtual void Render();
	virtual void Load(json::JSON& _json);

	Vector2D GetPosition() { return position; }
	void SetPositionX(int _x) { position.x = _x; }
	void SetPositionY(int _y) { position.y = _y; }
	void SetPosition(Vector2D _pos) { position = _pos; }

	std::string GetName() { return name; }
	void SetName(std::string _name) { name = _name; }

	//Circle GetCollisionCircle() const { return collisionCircle; }
};

#endif // !_ENTITY_H_