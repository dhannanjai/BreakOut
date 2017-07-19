#include "Ball.h"
#include"SpriteCodex.h"

Ball::Ball(Vec2 center, Vec2 dir)
{
	this->center = center;
	SetDirection(dir);
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::update(float dt)
{
	center += dir *(speed *dt);
}

bool Ball::DoWallCollision(const Rect & wall)
{
	Rect rect = GetRect();
	if (rect.left < wall.left)
	{
		center.x += (wall.left - rect.left);
		ReboundX();
		return true;
	}
	else if (rect.right > wall.right)
	{
		center.x += (wall.right - rect.right);
		ReboundX();
		return true;
	}

	if (rect.top < wall.top)
	{
		center.y += (wall.top - rect.top);
		ReboundY();
		return true;
	}
	else if (rect.bottom > wall.bottom)
	{
		center.y += (wall.bottom - rect.bottom);
		ReboundY();
		return true;
	}
	return false;
}

void Ball::ReboundX()
{
	dir.x = -dir.x;
}

void Ball::ReboundY()
{
	dir.y = -dir.y;
}

Rect Ball::GetRect() const
{
	return Rect(center, radius);
}

Vec2 Ball::Getcenter() const
{
	return center;
}

Vec2 Ball::GetVelocity() const
{
	return dir*speed;
}

void Ball::SetDirection(const Vec2 & dir)
{
	this->dir = Vec2(dir).Normalised();
}

void Ball::SetCenter(const Vec2 & center)
{
	this->center = center;
}

