#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "Component.h"

class Background : public Component
{
private:
	int scrollSpeed = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Background();
	~Background();

	void Initialize(int posY);
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
};

#endif // !_BACKGROUND_H_


