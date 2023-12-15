#pragma once
#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include "Vector2D.h"
class IRenderable;

class RenderSystem
{
private:
	static RenderSystem* instance;

	int width = 0;
	int height = 0;
	bool fullscreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	std::list<IRenderable*> iRenderables;

	Vector2D mousePosition;  
	bool isMousePressed = false;

	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;

public:
	static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	SDL_Renderer* GetRenderer() { return renderer; }

	bool GetMousePressed() { return isMousePressed; }
	Vector2D GetMousePosition() const 
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return Vector2D(x, y);
	}

	void AddIRenderable(IRenderable* _iRenderable) { iRenderables.push_back(_iRenderable); }
	void RemoveIRenderable(IRenderable* _iRenderable) { iRenderables.remove(_iRenderable); }
};

#endif // !_RENDERER_H_



