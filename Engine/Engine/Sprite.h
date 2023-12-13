#pragma once

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Renderable.h"

class Sprite : public Renderable
{
public:
	SDL_Rect targetRect = { 0,0,0,0 };

protected:
	//TextureAsset* texture = nullptr;
	//IVec2 size = {0, 0};
	SDL_Rect sourceRect = { 0,0,0,0 };

	void Initialize() override;
	void Destroy() override;
	void Update() override;
	void Render() override;

public:
	Sprite() = default;
	~Sprite() override = default;

	void SetSourceRect(SDL_Rect rect);
	//void SetTextureAsset(TextureAsset* texAsset);
	//void Load(json::JSON& node) override;
};

#endif // !_SPRITE_H_