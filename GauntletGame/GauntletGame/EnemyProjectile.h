#pragma once
#ifndef _ENEMY_PROJECTILE_H_
#define _ENEMY_PROJECTILE_H_

#include "Component.h"

class EnemyProjectile : public Component
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
	EnemyProjectile();
	~EnemyProjectile();

	void Initialize(int posX, int posY);
	void Update();
	void Destroy();
	void Render();
	void Load();
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() { return collisionCircle; }
};

#endif // !_ENEMY_PROJECTILE_H_
