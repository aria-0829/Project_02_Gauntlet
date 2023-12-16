// @file: CollisionDetection.h
//
// @brief: Holds a list of entities and checks for collisions between them
//
// @author: Tianhua Lian
// @date: 2023-12-15

#pragma once
#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

#include "Circle.h"
#include"Entity.h"

class CollisionDetection
{
private:
	std::list<Entity*> entities;

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
	
	void AddCollidable(Entity* _entity) { entities.push_back(_entity); }

	// Check collision for every entity
	void Update()
	{
		for (auto& entity1 : entities)
		{
			for (auto& entity2 : entities)
			{
				if (entity1 != entity2)
				{
					if (CheckCollision(entity1->GetCollisionCircle(), entity2->GetCollisionCircle()))
					{
						entity1->OnCollision(entity2);
						entity2->OnCollision(entity1);
					}
				}
			}
		}
		
	}
};
#endif // !_COLLISION_DETECTION_H_


