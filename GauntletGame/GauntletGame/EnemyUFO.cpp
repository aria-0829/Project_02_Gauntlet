#include "GameCore.h"

EnemyUFO::EnemyUFO()
{
	std::cout << "EnemyUFO Created" << std::endl;
}

EnemyUFO::~EnemyUFO()
{
	std::cout << "EnemyUFO Deleted" << std::endl;
}

void EnemyUFO::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex

	dstrect = { 0, 0, imageWidth, imageHeight };

	//Generate a random start height
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, (RenderSystem::Instance().GetHeight() - imageHeight * 3)); //Reseve 3 times the height as space for player
	dstrect.y = dis(gen);

	//Generate a random initial direction
	//1 means moving from left to right, -1 means moving from right to left
	std::uniform_int_distribution<int> dirDis(0, 1); //Random number 0 or 1
	direction = dirDis(gen) * 2 - 1; //Change it to -1 or 1

	if (direction == 1)
	{
		//Start from left
		dstrect.x = -imageWidth;
	}
	else
	{
		//Start from right
		dstrect.x = RenderSystem::Instance().GetWidth();
	}
}

void EnemyUFO::Update()
{
	if (direction == 1)
	{
		//Moving from left to right
		dstrect.x += speed;
	}
	else
	{
		//Moving from right to left
		dstrect.x -= speed;
	}

	//Change direction if ufo is out of window
	if (dstrect.x > RenderSystem::Instance().GetWidth() || dstrect.x < -imageWidth)
	{
		direction *= -1;
	}

	collisionCircle = { dstrect.x, dstrect.y, dstrect.w / 2 }; //Update collision circle
}

void EnemyUFO::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void EnemyUFO::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void EnemyUFO::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyUFO"))
	{
		json::JSON ufoData = _json["EnemyUFO"];

		if (ufoData.hasKey("speed"))
		{
			speed = ufoData["speed"].ToInt();  //Load speed
		}

		if (ufoData.hasKey("imagePath"))
		{
			imagePath = ufoData["imagePath"].ToString();  //Load image path
		}

		if (ufoData.hasKey("imageWidth"))
		{
			imageWidth = ufoData["imageWidth"].ToInt();  //Load image width
		}

		if (ufoData.hasKey("imageHeight"))
		{
			imageHeight = ufoData["imageHeight"].ToInt();  //Load image height
		}
	}
}
