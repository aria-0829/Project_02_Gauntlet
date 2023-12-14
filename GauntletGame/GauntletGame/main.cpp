#include "GameCore.h"

int main(int argc, char* argv[])
{
	GameEngine::Instance().Initialize();
	GameEngine::Instance().Update();
	GameEngine::Instance().Destroy();
	
	return 0;
}