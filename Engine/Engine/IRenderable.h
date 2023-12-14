#pragma once

#ifndef _IRENDERABLE_H_
#define _IRENDERABLE_H_

class IRenderable
{
	friend class RenderSystem;

protected:
	IRenderable();
	virtual ~IRenderable();

	//virtual void Render() = 0;

};

#endif // !_IRENDERABLE_H_

