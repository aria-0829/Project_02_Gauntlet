#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Component.h"

class Enemy : public Component
{
private:
	int speed = 0;
	int moveX = 0;
	int moveY = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Enemy();
	virtual ~Enemy() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;
	virtual void Render() = 0;
	int GetPositionY() { return dstrect.y; }
};
#endif // !_ENEMY_H_


