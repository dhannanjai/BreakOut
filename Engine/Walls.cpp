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
	gfx.DrawRect(static_cast<int>(rect.left - width), static_cast<int>(rect.top - width),	static_cast<int>(rect.right + width),	static_cast<int>(rect.top) ,				c);
	gfx.DrawRect(static_cast<int>(rect.left - width), static_cast<int>(rect.top),			static_cast<int>(rect.left),			static_cast<int>(rect.bottom),			c);
	gfx.DrawRect(static_cast<int>(rect.left - width), static_cast<int>(rect.bottom),		static_cast<int>(rect.right + width),	static_cast<int>(rect.bottom + width) ,	c);
	gfx.DrawRect(static_cast<int>(rect.right),			static_cast<int>(rect.top),			static_cast<int>(rect.right + width),	static_cast<int>(rect.bottom) ,			c);
}

Rect Walls::GetRect() const
{
	return rect;
}
