#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

//class Background;
class Player;
//class EnemySpawner;
//class AsteroidSpawner;

class Scene
{
private:
	static Scene* instance;

	std::list<Entity*> entities;

	/*Background* background1 = nullptr;
	Player* player = nullptr;
	EnemySpawner* enemySpawner = nullptr;
	AsteroidSpawner* asteroidSpawner = nullptr;*/

	inline explicit Scene() = default;
	inline ~Scene() = default;
	inline explicit Scene(Scene const&) = delete;
	inline Scene& operator=(Scene const&) = delete;

public:
	static Scene& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Scene();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	Entity* CreateEntity(const std::string& _entityName);
	Entity* GetEntityByName(std::string _entityName);
	void AddEntity(Entity* _entity);
	void CheckCollisions();
};
#endif // !_SCENE_H_
