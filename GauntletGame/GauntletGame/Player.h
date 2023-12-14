#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "IRenderable.h"
class Projectile;

class Player : public Entity, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Player, Entity)

private:
	int lives = 0;
	int moveX = 0;
	int moveY = 0;
	int windowWidth = 0;
	int windowHeight = 0;

	std::list<Projectile*> projectiles;
	json::JSON projectileData;

public:
	Player() = default;
	~Player() override = default;

	void Initialize() override;
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	void Shoot();
	void Damaged();
	void AddProjectile(Projectile* _projectile) { projectiles.push_back(_projectile); }
	void RemoveProjectile(Projectile* projectile) { projectiles.remove(projectile); }
	std::list<Projectile*> GetProjectiles() { return projectiles; }
};
#endif // !_PLAYER_H_


