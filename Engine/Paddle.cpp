#include "Paddle.h"

Paddle::Paddle(Vec2 pos, float width, float height)
	:
	halfZoneWidth(0.2*width / 2.0f),
	exitXfactor(static_cast<float>(maxExitratio * 2 / width)),
	fixedZoneExitX(static_cast<float>(halfZoneWidth * exitXfactor))
{
	this->pos = pos;
	this->height = height;
	this->width = width;
}

void Paddle::GetInput(Keyboard & kbd ,float dt)
{

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed*dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed*dt;
	}
}

void Paddle::Draw(Graphics & gfx) const
{
	Rect rect = GetRect();
	rect.Draw(gfx, c);
	rect.left += wingPadding;
	rect.right -= wingPadding;
	rect.Draw(gfx, wingColor);
}

Rect Paddle::GetRect() const
{
	return Rect(pos - Vec2(width / 2, height / 2), width, height);
}

void Paddle::DoWallCollision(const Rect & walls)
{
	Rect rect = GetRect();
	if (rect.left < walls.left)
		pos.x += (walls.left - rect.left);

	else if (rect.right > walls.right)
		pos.x += (walls.right - rect.right);

	if (rect.top < walls.top)
		pos.y += (walls.top - rect.top);
	else if (rect.bottom > walls.bottom)
		pos.y += (walls.bottom - rect.bottom);
}

bool Paddle::DoBallCollision(Ball & ball)
{
	Rect padRect = GetRect();
	Rect ballRect = ball.GetRect();
	Vec2 padCenter = Vec2((padRect.left + padRect.right) / 2, (padRect.top + padRect.bottom) / 2);
	Vec2 ballCenter = ball.Getcenter();

	/*
	This is to make sure that no matter what kind of collision takes place,
	the ball will never rebound in a manner so that the ball remains stuck
	inside the paddle.
	*/
	if (ball.GetVelocity().y > 0 && padRect.IsOverLappingWith(ballRect))
	{
		Vec2 dir;
		dir.y = -1.0f;

		if (ballCenter.y <= padCenter.y)
			ballCenter.y -= (ballRect.bottom - padRect.top);
		else
			ballCenter.y += (padRect.bottom - ballRect.top);

		ball.SetCenter(ballCenter);

		//That's it!!
		//Here on, we are making changes in the velocity of ball now.

		const float xDiffrence = ballCenter.x - padCenter.x;

		if (std::abs(xDiffrence) < halfZoneWidth)
		{
			if (xDiffrence < 0.0f)
				dir.x = -fixedZoneExitX;
			else
				dir.x = fixedZoneExitX;
		}
		else
			dir.x = xDiffrence * exitXfactor;

		ball.SetDirection(dir);
		//I tried so hard, 
		//and get so far, 
		//in the end,
		// the error always fucks up!!!
		return true;
	}
	return false;
}

