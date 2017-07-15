#include "Ball.h"
#include"SpriteCodex.h"

Ball::Ball(Rect rect)
	:
	rect(rect)
{
}

void Ball::Draw(Graphics & gfx) const
{
	Vec2 center = Vec2(rect.left + (rect.right - rect.left) / 2, rect.top + (rect.bottom - rect.top) / 2);
		SpriteCodex::DrawBall(center, gfx);
}

