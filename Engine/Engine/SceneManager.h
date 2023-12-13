#pragma once

#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

class Scene;
class Entity;

class SceneManager 
{
	friend class GameEngine;
private:
	static SceneManager* instance;

	// Not part of the provided UML diagram, however would likely be required
	std::map<std::string, int> _sceneNameToId;
	std::list<Scene*> scenes;
	Scene* activeScene = nullptr;

	inline explicit SceneManager() = default;
	inline ~SceneManager() = default;
	inline explicit SceneManager(SceneManager const&) = delete;
	inline SceneManager& operator=(SceneManager const&) = delete;

protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _json);

public:
	static SceneManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return *instance;
	}

	Scene* AddScene(json::JSON& _json);
	void RemoveScene(std::string);
	void SetActiveScene(int);
	Scene* GetActiveScene() const { return activeScene; }
	Entity* FindEntityById(int);
};

#endif // !_SCENE_MANAGER_H_