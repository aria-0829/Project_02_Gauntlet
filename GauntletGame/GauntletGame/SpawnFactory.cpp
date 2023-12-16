#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(SpawnFactory)

void SpawnFactory::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;
}

void SpawnFactory::Update()
{
	Entity::Update();

	if (spawnedList.size() < 10)
	{
		timeCounter += GameTime::Instance().DeltaTime();
		if (timeCounter >= spawnInterval)
		{
			Spawn();
			timeCounter = 0.0f;
		}
	}
}

void SpawnFactory::Spawn()
{
	std::cout << "Creating: " << spawnName << std::endl;
	Entity* entity = Scene::Instance().CreateEntity(spawnName);
	spawnedList.push_back(entity);
	entity->Load(spawnData);
	entity->SetPosition(position);
	entity->Initialize();
}

void SpawnFactory::Load(json::JSON& _json)
{
	Entity::Load(_json);

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString();  //Load image path
	}

	if (_json.hasKey("imageWidth"))
	{
		imageWidth = _json["imageWidth"].ToInt();  //Load image width
	}

	if (_json.hasKey("imageHeight"))
	{
		imageHeight = _json["imageHeight"].ToInt();  //Load image height
	}
	if (_json.hasKey("SpawnInterval"))
	{
		spawnInterval = _json["SpawnInterval"].ToInt();  //Load image height
	}

	spawnName = _json["SpawnName"].ToString();
	spawnData = _json["SpawnData"];
}
