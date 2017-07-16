#include "Brick.h"

Brick::Brick(Rect rect, Color c)
	:
	rect(rect),
	c(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if(!isCollided)
		rect.Draw(gfx, c);
}

bool Brick::BallCollision(Ball & ball)
{
	if (!isCollided)
	{
		isCollided = rect.IsOverLappingWith(ball.GetRect());
		return isCollided;
	}
}
