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

Vec2 Ball::Getcenter() const
{
	return center;
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

bool Ball::DoPaddleCollision(const Paddle & pad)
{
	Rect padRect = pad.GetRect();
	Rect ballRect = GetRect();
	/*
	This is to make sure that no matter what kind of collision takes place, 
	the ball will never rebound in a manner so that the ball remains stuck 
	inside the paddle.
	*/
	if (padRect.IsOverLappingWith(ballRect))
	{
		float padCenter_y = padRect.top + (padRect.bottom - padRect.top) / 2;
		if (center.y <= padCenter_y)
			center.y -= (ballRect.bottom - padRect.top);
		else
			center.y += (padRect.bottom - ballRect.top);

		ReboundY();
		return true;
	}
	return false;

	//That's it!!
}

