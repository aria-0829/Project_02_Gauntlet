#pragma once
#ifndef _ASTEROID_SPAWNER_H_
#define _ASTEROID_SPAWNER_H_

#include "Component.h"
class Star;
class Asteroid;

class AsteroidSpawner : public Component
{
private:
	std::list<Asteroid*> asteroids;
	json::JSON asteroidData;
	std::list<Star*> stars;
	json::JSON starData;

public:
	AsteroidSpawner();
	~AsteroidSpawner();

	void Update();
	void Destroy();
	void SpawnAsteroids();
	void AddAsteroid(Asteroid* _asteroid);
	void SpawnStars();
	void Load();
};

#endif // !_ASTEROID_SPAWNER_H_


