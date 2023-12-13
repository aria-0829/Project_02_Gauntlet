#pragma once
#ifndef _ENEMY_SHIP_H_
#define _ENEMY_SHIP_H_

#include "Component.h"
class EnemyProjectile;
class Circle;

class EnemyShip : public Component
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	std::list<EnemyProjectile*> enemyProjectiles;
	Circle collisionCircle = { 0, 0, 0 };

public:
	EnemyShip();
	~EnemyShip();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() const { return collisionCircle; }
};
#endif // !_ENEMY_SHIP_H_



