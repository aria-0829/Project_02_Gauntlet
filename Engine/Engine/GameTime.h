#pragma once
#ifndef _GAME_TIME_H_
#define _GAME_TIME_H_

class GameTime
{
private:
	void Initialize();

	unsigned int frameCount = 0;
	std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0.0f);
	std::chrono::duration<float> totalTime = std::chrono::duration<float>(0.0f);
	std::chrono::time_point<std::chrono::system_clock> beginTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;

	static GameTime* instance;

	inline explicit GameTime() = default;
	inline ~GameTime() = default;
	inline explicit GameTime(GameTime const&) = delete;
	inline GameTime& operator=(GameTime const&) = delete;

public:
	static GameTime& Instance()
	{
		if (instance == nullptr)
		{
			instance = new GameTime();
			instance->Initialize();
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

	void Update();

	float DeltaTime() { return deltaTime.count(); }
	float TotalTime() { return totalTime.count(); }
	unsigned int FrameCount() { return frameCount; }
};

#endif // !_GAME_TIME_H_