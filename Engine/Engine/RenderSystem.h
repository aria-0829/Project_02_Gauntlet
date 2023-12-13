#pragma once
#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

class Renderable;

class RenderSystem
{
private:
	static RenderSystem* instance;

	std::string name = "GAME";
	int width = 0;
	int height = 0;
	bool fullscreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	std::list<Renderable*> renderables;

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

	void AddRenderable(Renderable* _renderable) { renderables.push_back(_renderable); }
	void RemoveRenderable(Renderable* _renderable) { renderables.remove(_renderable); }
};

#endif // !_RENDERER_H_



