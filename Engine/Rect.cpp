#include "Rect.h"

Rect::Rect(float top, float bottom, float left, float right)
	:
	top(top),
	bottom(bottom),
	left(left),
	right(right)
{
}

Rect::Rect(const Vec2 topLeft, const Vec2 bottomRight)
	:
	Rect(topLeft.y, bottomRight.y, topLeft.x, bottomRight.x)
{
}

Rect::Rect(const Vec2 topLeft, float width, float height)
	:
	Rect(topLeft, topLeft + Vec2(width, height))
{
}

Rect::Rect(const Vec2 center, float radius)
	:
	Rect(center - Vec2(radius, radius), center + Vec2(radius, radius))
{
}

void Rect::Draw(Graphics & gfx , Color c) const
{
	gfx.DrawRect(left, top, right, bottom,c);
}
