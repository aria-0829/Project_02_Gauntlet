#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(ObjectSpawner)

void ObjectSpawner::Initialize()
{
	for (auto barrel : barrels)
	{
		barrel->Initialize();
	}

	for (auto wall : walls)
	{
		wall->Initialize();
	}
}

void ObjectSpawner::Update()
{
	for (auto barrel : barrels)
	{
		barrel->Update();
	}

	for (auto wall : walls)
	{
		wall->Update();
	}
}

void ObjectSpawner::Render()
{
	//Entity::Render();

	//Render barrels
	for (auto barrel : barrels)
	{
		barrel->Render();
	}

	//Render walls
	for (auto wall : walls)
	{
		wall->Render();
	}
}

void ObjectSpawner::Destroy()
{
	//Destroy barrels
	for (auto barrel : barrels)
	{
		barrel->Destroy();
		delete barrel;
	}
	barrels.clear();

	//Destroy walls
	for (auto wall : walls)
	{
		wall->Destroy();
		delete wall;
	}
	walls.clear();
}

void ObjectSpawner::Load(json::JSON& _json)
{
	Entity::Load(_json);
	
	// Load the barrels
	if (_json.hasKey("Barrel"))
	{
		barrelData = _json["Barrel"];
	}
	if (_json.hasKey("BarrelPositions"))
	{
		json::JSON barrelPositions = _json["BarrelPositions"];

		for (json::JSON& barrel : barrelPositions.ArrayRange())
		{
			if (barrel.hasKey("Position"))
			{
				json::JSON barrelPos = barrel["Position"];

				Barrel* barrel = new Barrel();
				barrels.push_back(barrel);
				barrel->Load(barrelData);

				if (barrelPos.hasKey("x") && barrelPos.hasKey("y")) 
				{ 
					barrel->SetPosition(Vector2D(barrelPos["x"].ToFloat(), barrelPos["y"].ToFloat()));
				}
			}
		}
	}

	// Load the walls
	if (_json.hasKey("Wall"))
	{
		wallData = _json["Wall"];
	}
	if (_json.hasKey("WallPositions"))
	{
		json::JSON wallPositions = _json["WallPositions"];

		for (json::JSON& wall : wallPositions.ArrayRange())
		{
			if (wall.hasKey("Position"))
			{
				json::JSON wallPos = wall["Position"];

				Wall* wall = new Wall();
				walls.push_back(wall);
				wall->Load(wallData);


				//if (wallPos.hasKey("x")) { wall->SetPositionX(wallPos["x"].ToInt()); }
				//if (wallPos.hasKey("y")) { wall->SetPositionY(wallPos["y"].ToInt()); }
				if (wallPos.hasKey("x") && wallPos.hasKey("y"))
				{
					wall->SetPosition(Vector2D(wallPos["x"].ToFloat(), wallPos["y"].ToFloat()));
				}
			}
		}
	}
}

