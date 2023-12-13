#include "EngineCore.h"

#include "GameEngine.h"

RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::Initialize()
{
	//Create window and RenderSystem
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Game::Instance().Initialize();

	std::cout << "RenderSystem Initialized" << std::endl;
}

void RenderSystem::Update()
{
	int FPS = 60;
	int frameDelay = 1000 / FPS;
	Uint32 frameStart = SDL_GetTicks();
	int frameTime = SDL_GetTicks() - frameStart;
	
	if (frameDelay > frameTime)
	{
	SDL_Delay(frameDelay - frameTime);
	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			GameEngine::Instance().setGameRunning(false);
			Destroy();
		}
		else
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				//GameEngine::Instance().setGameRunning(false);

			}
		}
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Render things here
	//Game::Instance().Update();
	//Game::Instance().GetPlayer()->Render();
	for (Renderable* renderable : renderables)
	{
		renderable->Render();
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Destroy()
{
	//Destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	//Game::Instance().Destroy();

	if (instance != nullptr)
	{
		delete instance;
	}

	std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Load(json::JSON& _json)
{
	if (_json.hasKey("RenderSettings"))
	{
		json::JSON renderSettings = _json["RenderSettings"];

		if (renderSettings.hasKey("name"))
		{
			name = renderSettings["name"].ToString();
		}
		if (renderSettings.hasKey("width"))
		{
			width = renderSettings["width"].ToInt();
		}

		if (renderSettings.hasKey("height"))
		{
			height = renderSettings["height"].ToInt();
		}

		if (renderSettings.hasKey("fullscreen"))
		{
			fullscreen = renderSettings["fullscreen"].ToBool();
		}
	}
}

