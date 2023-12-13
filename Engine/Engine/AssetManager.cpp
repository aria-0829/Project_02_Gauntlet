#include "AssetManager.h"
#include "EngineCore.h"

AssetManager* AssetManager::instance = nullptr;

void AssetManager::Initialize()
{
	std::cout << "AssetManager Initialized" << std::endl << std::endl;
}

SDL_Texture* AssetManager::LoadTexture(const char* texturePath)
{
	SDL_Surface* tempSurface = IMG_Load(texturePath);

	if (!tempSurface) {
		std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(RenderSystem::Instance().GetRenderer(), tempSurface);

	SDL_FreeSurface(tempSurface);
	return texture;
}
