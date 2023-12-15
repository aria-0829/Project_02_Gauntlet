#include "GameCore.h"

IMPLEMENT_DYNAMIC_CLASS(Player)

void Player::Initialize()
{
	windowWidth = RenderSystem::Instance().GetWidth();
	windowHeight = RenderSystem::Instance().GetHeight();

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { windowWidth / 2, (windowHeight - imageHeight), imageWidth, imageHeight};  //Player starting position at the bottom middle of the window
	std::cout << "Player Initialized" << std::endl << std::endl;
}

void Player::Update()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	GameTime& gameTime = GameTime::Instance();
	float deltaTime = gameTime.DeltaTime();

	if (currentKeyStates[SDL_SCANCODE_W]) {
		moveY -= speed;
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		moveX -= speed;
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		moveY += speed;
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		moveX += speed;
	}
	if (currentKeyStates[SDL_SCANCODE_SPACE]) {
		Shoot();
	}

	projectiles.remove_if([](Projectile* projectile)
	{
		projectile->Update();
		//projectile->Render();

		//Check if the projectile is out of the window
		if (projectile->GetPositionY() < 0)
		{
			projectile->Destroy();
			delete projectile;
			return true; //Remove the projectile
		}
		return false; //Keep the projectile
	});

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


void Player::Shoot()
{
	static int frameCount = 0;
	const int spawnInterval = 5;

	if (frameCount % spawnInterval == 0)
	{
		Projectile* projectile = new Projectile();
		AddProjectile(projectile);
		projectile->Load(projectileData);
		projectile->SetPositionX(dstrect.x + imageWidth / 2);
		projectile->SetPositionY(dstrect.y);
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
	//Apply the movement to the playerDstrect
	dstrect.x = windowWidth / 2 + moveX;
	dstrect.y = (windowHeight - imageHeight) + moveY;

	//Keep the player within the window
	if (moveX < -(windowWidth / 2))
	{
		moveX = -(windowWidth / 2);
	}
	if (moveX > (windowWidth - imageWidth) - windowWidth / 2)
	{
		moveX = (windowWidth - imageWidth) - windowWidth / 2;
	}

	if (moveY < -(windowHeight - imageHeight))
	{
		moveY = -(windowHeight - imageHeight);
	}
	if (moveY > 0)
	{
		moveY = 0;
	}

	collisionCircle = { dstrect.x, dstrect.y, imageWidth / 2 };

	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);  //Render the player
}

void Player::Load(json::JSON& _json)  //Load player data from json file
{
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
