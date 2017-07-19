#include "Ball.h"
#include"SpriteCodex.h"

Ball::Ball(Vec2 center, Vec2 dir)
{
	this->center = center;
	this->dir = dir.Normalised();
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

bool Ball::DoPaddleCollision(const Paddle & pad)
{
	Rect padRect = pad.GetRect();
	Rect ballRect = GetRect();
	Vec2 padCenter = Vec2((padRect.left + padRect.right) / 2, padRect.top + (padRect.bottom - padRect.top) / 2);
	/*
	This is to make sure that no matter what kind of collision takes place, 
	the ball will never rebound in a manner so that the ball remains stuck 
	inside the paddle.
	*/
	if ( dir.y > 0 &&  padRect.IsOverLappingWith( ballRect ) )
	{
		
		if (center.y <= padCenter.y)
			center.y -= (ballRect.bottom - padRect.top);
		else
			center.y += (padRect.bottom - ballRect.top);

		//That's it!!
		//Here on, we are making changes in the velocity of ball now.

		const float xDiffrence = center.x - padCenter.x;
		dir = Vec2(xDiffrence * exitXfactor, -1.0f).Normalised();

		//I tried so hard, 
		//and get so far, 
		//in the end,
		// the error always fucks up!!!
		return true;
	}
	return false;

	
}

