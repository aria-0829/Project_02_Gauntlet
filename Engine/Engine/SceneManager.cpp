#include "EngineCore.h"
#include "Scene.h"

SceneManager* SceneManager::instance = nullptr;

void SceneManager::Initialize() 
{
	if (activeScene == nullptr) 
	{
		return;
	}

	activeScene->Initialize();
}

void SceneManager::Destroy() 
{
	activeScene = nullptr;

	for (const auto& scene : scenes) 
	{
		scene->Destroy();
		delete scene;
	}

	scenes.clear();
}

void SceneManager::Update() 
{
	if (activeScene == nullptr) 
	{
		return;
	}

	activeScene->Update();
}

void SceneManager::Load(json::JSON& _json)
{
	if (_json.hasKey("SceneManager"))
	{
		json::JSON sceneManagerData = _json["SceneManager"];
		std::string sceneFile = sceneManagerData["sceneFile"].ToString();

		// Load Scene.json
		std::ifstream inputStream(sceneFile);
		std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
		json::JSON sceneData = json::JSON::Load(str);

		Scene* scene = AddScene(sceneData);
		activeScene = scene;
		//activeScene->isEnabled = true;
	}
}

Scene* SceneManager::AddScene(json::JSON& _json)
{
	Scene* scene = new Scene();

	scene->Load(_json);
	scene->Initialize();

	scenes.push_back(scene);

	return scene;

	// Add the scene filename and ID to the map
	//_sceneNameToId.emplace(_fileName, (int)scenes.size() - 1);
}

void SceneManager::RemoveScene(std::string _fileName) 
{
	// Check if we have a scene loaded with the given filename
	const auto scene_find = _sceneNameToId.find(_fileName);

	if (scene_find == _sceneNameToId.end()) 
	{
		std::cout << "ERROR: Invalid Scene Name (" << _fileName << "). Cannot Remove Scene." << std::endl;
		return;
	}

	// Get the ID of the scene to remove
	const int id = scene_find->second;
	_ASSERT(id >= 0 && id < (int)scenes.size());

	// Navigate to the correct scene
	auto scene = scenes.begin();
	std::advance(scene, id);

	// Destroy and clean up the scene's memory
	(*scene)->Destroy();
	delete* scene;

	// Remove the scene from the scene list
	scenes.erase(scene);
	_sceneNameToId.erase(_fileName);
}

void SceneManager::SetActiveScene(int _id) 
{
	// Check if our ID is valid
	if (_id < 0 || _id > (int)scenes.size()) 
	{
		std::cout << "ERROR: Invalid ID (" << _id << "). Cannot Set Active Scene." << std::endl;
		return;
	}

	// Navigate to the correct scene
	auto scene = scenes.begin();
	std::advance(scene, _id);

	// Set the scene as the active scene
	activeScene = *scene;
}

Entity* SceneManager::FindEntityById(int id) 
{
	if (activeScene == nullptr) 
	{
		return nullptr;
	}

	return activeScene->FindEntityById(id);
}
