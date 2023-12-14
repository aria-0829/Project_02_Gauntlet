#pragma once
#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

//#include "Player.h"
//#include "Projectile.h"
//#include "EnemyShip.h"
//#include "EnemyUFO.h"
//#include "EnemyProjectile.h"
//#include "Asteroid.h"
#include "Circle.h"

class CollisionDetection
{
private:
	static CollisionDetection* instance;

	inline explicit CollisionDetection() = default;
	inline ~CollisionDetection() = default;
	inline explicit CollisionDetection(CollisionDetection const&) = delete;
	inline CollisionDetection& operator=(CollisionDetection const&) = delete;

public:
	static CollisionDetection& Instance()
	{
		if (instance == nullptr)
		{
			instance = new CollisionDetection();
		}
		return *instance;
	}

	void Destroy()
	{
		if (instance != nullptr)
		{
			delete instance;
		}
	}

	bool CheckCollision(const Circle& collisionCircle1, const Circle& collisionCircle2);

};
#endif // !_COLLISION_DETECTION_H_


