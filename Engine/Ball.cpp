#include "Ball.h"
#include"SpriteCodex.h"

Ball::Ball(Vec2 center, Vec2 vel)
{
	this->center = center;
	this->vel = vel;
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::update(float dt)
{
	center += (vel*dt);
}

void Ball::DoWallCollision(const Rect & wall)
{
	Rect rect = GetRect();
	if (rect.left < wall.left)
	{
		center.x += (wall.left - rect.left);
		ReboundX();
	}
	else if (rect.right > wall.right)
	{
		center.x += (wall.right - rect.right);
		ReboundX();
	}

	if (rect.top < wall.top)
	{
		center.y += (wall.top - rect.top);
		ReboundY();
	}
	else if (rect.bottom > wall.bottom)
	{
		center.y += (wall.bottom - rect.bottom);
		ReboundY();
	}
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

Rect Ball::GetRect() const
{
	return Rect(center, radius);
}

