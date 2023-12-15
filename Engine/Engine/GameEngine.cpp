#include "EngineCore.h"

GameEngine* GameEngine::instance = nullptr;

void GameEngine::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("../Data/GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	GameTime::Instance().Initialize();
	AssetManager::Instance().Initialize();

	RenderSystem::Instance().Load(documentData);
	RenderSystem::Instance().Initialize();

	Scene::Instance().Load(documentData);
	Scene::Instance().Initialize();

	std::cout << "Game Initialized" << std::endl << std::endl;
}

void GameEngine::Update()
{
	while (isRunning)
	{
		GameTime::Instance().Update();
		RenderSystem::Instance().Update();
	}
}

void GameEngine::Destroy()
{
	GameTime::Instance().Destroy();
	RenderSystem::Instance().Destroy();
	AssetManager::Instance().Destroy();
	if (instance != nullptr)
	{
		delete instance;
	}
}

void GameEngine::Load(json::JSON& _json)
{
	std::cout << "Game Loading..." << std::endl << std::endl;

}

void GameEngine::Save()
{
	std::cout << "Game Saving..." << std::endl << std::endl;


	std::cout << "Game Save Complete" << std::endl << std::endl;
}
