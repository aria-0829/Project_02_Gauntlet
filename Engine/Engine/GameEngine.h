#pragma once
#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_
#include "json.hpp"

class GameEngine
{
private:
	static GameEngine* instance;

	bool isRunning = true;

	inline explicit GameEngine() = default;
	inline ~GameEngine() = default;
	inline explicit GameEngine(GameEngine const&) = delete;
	inline GameEngine& operator=(GameEngine const&) = delete;

public:
	static GameEngine& Instance()
	{
		if (instance == nullptr)
		{
			instance = new GameEngine();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	void Save();
	bool GameRunning() { return isRunning; }
	void setGameRunning(bool value) { isRunning = value; }
};
#endif // !_GAME_ENGINE_H_



