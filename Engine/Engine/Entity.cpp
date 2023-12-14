#include "EngineCore.h"

IMPLEMENT_DYNAMIC_CLASS(Entity)

void Entity::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex

	dstrect = { posX, posY, imageWidth, imageHeight }; //Set position and size

	std::cout << "Entity Initialized" << std::endl << std::endl;
}

void Entity::Update()
{
	std::cout << "Entity Updating..." << std::endl << std::endl;
	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void Entity::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Entity::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Entity::Load(json::JSON& _json)
{
}
