#pragma once
#ifndef _GAME_H_
#define _GAME_H_

class UI;
class Background;
class Player;
class EnemySpawner;
class AsteroidSpawner;

class Game
{
private:
	static Game* instance;

	UI* ui = nullptr;
	Background* background1 = nullptr;
	Background* background2 = nullptr;
	Player* player = nullptr;
	EnemySpawner* enemySpawner = nullptr;
	AsteroidSpawner* asteroidSpawner = nullptr;

	inline explicit Game() = default;
	inline ~Game() = default;
	inline explicit Game(Game const&) = delete;
	inline Game& operator=(Game const&) = delete;

public:
	static Game& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Game();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	Player* GetPlayer() { return player; }
	void CheckCollisions();
};
#endif // !_GAME_H_
