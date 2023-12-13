#include "GameCore.h"

Enemy::Enemy()
{
	std::cout << "Enemy Created" << std::endl;
}

void Enemy::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex
}

void Enemy::Update()
{
	dstrect.y += speed;

}

void Enemy::Destroy()
{
	SDL_DestroyTexture(tex);
}

void Enemy::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

