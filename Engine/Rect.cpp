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

bool Rect::IsOverLappingWith(const Rect & other) const
{
	return  right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;

}

void Rect::Draw(Graphics & gfx , Color c) const
{
	gfx.DrawRect(static_cast<int>(left), static_cast<int>(top), static_cast<int>(right), static_cast<int>(bottom), c);
}
