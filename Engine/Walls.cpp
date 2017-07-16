#include "Walls.h"
#include<assert.h>

Walls::Walls(Rect rect, float width)
{
	assert(rect.top - width >= 0);
	assert(rect.bottom + width <= int(Graphics::ScreenHeight));

	assert(rect.left - width >= 0);
	assert(rect.right + width <= int(Graphics::ScreenWidth));
	this->rect = rect;
	this->width = width;
}

void Walls::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect.left - width, rect.top - width,	rect.right + width, rect.top ,				c);
	gfx.DrawRect(rect.left - width, rect.top,			rect.left,			rect.bottom,			c);
	gfx.DrawRect(rect.left - width, rect.bottom,		rect.right + width, rect.bottom + width ,	c);
	gfx.DrawRect(rect.right,		rect.top,			rect.right + width, rect.bottom ,			c);
}

Rect Walls::GetRect() const
{
	return rect;
}
