#pragma once
#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include "SDL.h"
#include "SDL_image.h"

class AssetManager
{
private:
	static AssetManager* instance;

	inline explicit AssetManager() = default;
	inline ~AssetManager() = default;
	inline explicit AssetManager(AssetManager const&) = delete;
	inline AssetManager& operator=(AssetManager const&) = delete;

public:
	static AssetManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new AssetManager();
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

	void Initialize();
	SDL_Texture* LoadTexture(const char* texturePath);
	//void LoadFont(std::string name, std::string fileName);
};

#endif // !_ASSETMANAGER_H_


