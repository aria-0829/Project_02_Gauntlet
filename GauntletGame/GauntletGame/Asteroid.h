#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "Component.h"

class Asteroid : public Component
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };

public:
	Asteroid();
	~Asteroid();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() const { return collisionCircle; }
};
#endif // !_ASTEROID_H_


