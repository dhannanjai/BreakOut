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

bool Rect::IsContainedBy(const Rect & other) const
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

Rect Rect::GetExpanded(float offset) const
{
	return Rect(top - offset, bottom + offset, left - offset, right + offset);
}

Vec2 Rect::GetCenter() const
{
	return Vec2((left + right) / 2, (top + bottom) / 2);
}
