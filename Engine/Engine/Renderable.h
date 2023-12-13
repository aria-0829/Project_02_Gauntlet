#pragma once

#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "Component.h"

class Renderable : public Component
{
	friend class RenderSystem;

private:

    /**
    * @SetFilterColor
    *
    * Allows the user to set a color filter that will be applied overtop of their sprite.
    * Takes RGB Values along with an Alpha. Nothing clamps the values so numbers bigger then 255
    * or less than 0 will loop in their respective directions.
    */
	void SetFilterColor(int r, int g, int b, int a);

	virtual void Render() = 0;

protected:
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Color filterColor = { 255, 255, 255 };

	Renderable();
	~Renderable();
};

#endif // !_RENDERABLE_H_

