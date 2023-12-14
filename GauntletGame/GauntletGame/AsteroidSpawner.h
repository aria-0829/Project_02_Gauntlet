#pragma once
#ifndef _ASTEROID_SPAWNER_H_
#define _ASTEROID_SPAWNER_H_

#include "Entity.h"
#include "IRenderable.h"

class Star;
class Asteroid;

class AsteroidSpawner : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(AsteroidSpawner, Entity)

private:
	std::list<Asteroid*> asteroids;
	json::JSON asteroidData;
	std::list<Star*> stars;
	json::JSON starData;

public:
	AsteroidSpawner();
	~AsteroidSpawner();

	void Initialize() override;
	void Update();
	void Destroy();
	void SpawnAsteroids();
	void AddAsteroid(Asteroid* _asteroid);
	void SpawnStars();
	void Load(json::JSON& _json);
};

#endif // !_ASTEROID_SPAWNER_H_


