#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::Initialize()
{
	Entity::Initialize();

	dstrect.w = imageWidth;
	dstrect.h = imageHeight;

	std::cout << "Player Initialized" << std::endl << std::endl;
}

void Player::Update()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	float deltaTime = GameTime::Instance().DeltaTime();

	// Player Movement
	if (currentKeyStates[SDL_SCANCODE_A])
	{
		position.x -= speed * deltaTime;
	}
	if (currentKeyStates[SDL_SCANCODE_D])
	{
		position.x += speed * deltaTime;
	}
	if (currentKeyStates[SDL_SCANCODE_W])
	{
		position.y -= speed * deltaTime;
	}
	if (currentKeyStates[SDL_SCANCODE_S])
	{
		position.y += speed * deltaTime;
	}

	//Keep the player within the window
	int windowWidth = RenderSystem::Instance().GetWidth();
	int windowHeight = RenderSystem::Instance().GetHeight();

	if (position.x < 0) { position.x = 0; }
	if (position.x > windowWidth - imageWidth) { position.x = windowWidth - imageWidth; }
	if (position.y < 0) { position.y = 0; }
	if (position.y > windowHeight - imageHeight) { position.y = windowHeight - imageHeight; }

	// Player Shoot
	if (RenderSystem::Instance().GetMousePressed())
	{
		Shoot(RenderSystem::Instance().GetMousePosition());
	}

	//Update the projectiles
	for (auto projectile : projectiles)
	{
		projectile->Update();
	}
	
	//projectiles.remove_if([](Projectile* projectile)
	//{
	//	projectile->Update();
	//	//projectile->Render();

	//	//Check if the projectile is out of the window
	//	if (projectile->GetPosition().y < 0)
	//	{
	//		projectile->Destroy();
	//		delete projectile;
	//		return true; //Remove the projectile
	//	}
	//	return false; //Keep the projectile
	//});

	if (lives <= 0)
	{
		Destroy();
		//Game::Instance().setGameRunning(false);
	}
}

void Player::Destroy()
{
	for (auto projectile : projectiles)
	{
		projectile->Destroy();
		delete projectile;
	}
	projectiles.clear();

	Entity::Destroy();
}

void Player::Shoot(const Vector2D& _mousePos)
{
	static int frameCount = 0;
	const int spawnInterval = 5;

	if (frameCount % spawnInterval == 0)
	{
		//Vector2D direction = position - _mousePos;
		//std::cout << position.x << ", " << position.y << std::endl;
		//direction.Normalize();
		//std::cout << "Direction: " << direction.x << ", " << direction.y << std::endl;
		
		Projectile* projectile = new Projectile();
		AddProjectile(projectile);
		projectile->Load(projectileData);
		projectile->SetPositionX(_mousePos.x);
		projectile->SetPositionY(_mousePos.y);
		//projectile->SetDirection(direction);
		projectile->Initialize();
	}

	++frameCount;
}

void Player::Damaged()
{
	lives--;
	std::cout << "Player Damaged" << std::endl;
	std::cout << "Lives: " << lives << std::endl;
}

void Player::Render()
{
	for (auto projectile : projectiles)
	{
		projectile->Render();
	}

	collisionCircle = { dstrect.x, dstrect.y, imageWidth / 2 };

	dstrect = { (int)position.x, (int)position.y, dstrect.w, dstrect.h }; //Set position and size
	
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);  //Render the player
}

void Player::Load(json::JSON& _json)  //Load player data from json file
{
	Entity::Load(_json);

	if (_json.hasKey("lives"))
	{
		lives = _json["lives"].ToInt();  //Load the player lives
		std::cout << "Lives: " << lives << std::endl;
	}

	if (_json.hasKey("speed"))
	{
		speed = _json["speed"].ToInt();  //Load the player speed
	}

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString();  //Load the player image path
	}

	if (_json.hasKey("imageWidth"))
	{
		imageWidth = _json["imageWidth"].ToInt();  //Load the player image width
	}

	if (_json.hasKey("imageHeight"))
	{
		imageHeight = _json["imageHeight"].ToInt();  //Load the player image height
	}

	if (_json.hasKey("Projectile"))
	{
		projectileData = _json["Projectile"];  //Load the player projectile data
	}
	
}
