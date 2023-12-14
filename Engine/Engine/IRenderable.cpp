#include "EngineCore.h"

IRenderable::IRenderable()
{
	//RenderSystem::Instance().AddIRenderable(this);
}

IRenderable::~IRenderable()
{
	//RenderSystem::Instance().RemoveIRenderable(this);
}
