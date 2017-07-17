#include "Brick.h"

Brick::Brick(Rect rect, Color c)
	:
	rect(rect),
	c(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (isCollided == false)
	{
		Rect rect_pad = Rect(rect.top + padding, rect.bottom - padding, rect.left + padding, rect.right - padding);
		rect_pad.Draw(gfx, c);
	}
}

bool Brick::BallCollision(Ball & ball)
{
	if (isCollided != true)
	{
		isCollided = rect.IsOverLappingWith(ball.GetRect());
		ball.ReboundY();
	}
	return isCollided;
}
