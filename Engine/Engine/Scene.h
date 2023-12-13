#pragma once

#ifndef _SCENE_H_
#define _SCENE_H_

class Entity;

class Scene 
{
	friend class SceneManager;

private:
	std::list<Entity*> entities;
	std::string name;
	int id;

protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _json);

public:
	Entity* CreateEntity();
	void RemoveEntity(Entity* _entity);
	Entity* FindEntityById(int id);
};

#endif // !_SCENE_H_