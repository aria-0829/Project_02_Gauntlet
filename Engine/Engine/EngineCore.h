#pragma once

#define NOMINMAX

#pragma comment(lib, "rpcrt4.lib")
#include <windows.h>

#include <assert.h>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "json.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "StandardTypes.h"
#include "TypeClass.h"

// Engine Stuff
//#include "GameEngine.h"
#include "GameTime.h"
#include "AssetManager.h"

#include "CollisionDetection.h"
#include "Circle.h"

#include "RenderSystem.h"
#include "Renderable.h"
#include "Sprite.h"
//#include "AnimatedSprite.h"
//#include "Animation.h"
#include "UI.h"

#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Entity.h"
#include "Component.h"
//#include "Transform.h"
