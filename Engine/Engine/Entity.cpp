#include "EngineCore.h"

IMPLEMENT_DYNAMIC_CLASS(Entity)

void Entity::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex

	dstrect = { position.x, position.y, imageWidth, imageHeight }; //Set position and size

	std::cout << this->GetName() << " Initialized" << std::endl << std::endl;
}

void Entity::Update()
{
	

	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void Entity::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Entity::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Entity::Load(json::JSON& _json)
{
	if (_json.hasKey("Position"))
	{
		json::JSON positionData = _json["Position"];

		if (positionData.hasKey("x"))
		{
			position.x = positionData["x"].ToInt();

			std::cout<< this->GetName() << ": Position: x: " << position.x << std::endl;
		}
		if (positionData.hasKey("y"))
		{
			position.y = positionData["y"].ToInt();
			std::cout << "y: " << position.y << std::endl;
		}
	}
}
