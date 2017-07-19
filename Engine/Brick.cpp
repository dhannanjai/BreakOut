#include "Brick.h"

Brick::Brick(const Rect& rect, Color c)
	:
	rect(rect),
	hasCollided(false),
	c(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (hasCollided == false)
	{
		Rect rect_pad = Rect(rect.top + padding, rect.bottom - padding, rect.left + padding, rect.right - padding);
		rect_pad.Draw(gfx, c);
	}
}

bool Brick::BallCollision(const Ball & ball)const
{
	return !hasCollided && rect.IsOverLappingWith(ball.GetRect());
}

float Brick::CalculateDistanceFromBall(const Ball & ball) const
{
	Vec2 brickPos = Vec2(rect.left + (rect.right - rect.left) / 2, rect.top + (rect.bottom - rect.top) / 2);
	
	return (brickPos - ball.GetVelocity()).MagnitudeSq();
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	Vec2 ballpos = ball.Getcenter();

	if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.Getcenter() - GetCenter()).x))
		ball.ReboundY();
	else if (ballpos.x >= rect.left && ballpos.x <= rect.right)
		ball.ReboundY();
	else
		ball.ReboundX();
	hasCollided = true;
}

Vec2 Brick::GetCenter() const
{
	return Vec2((rect.left + rect.right) / 2.0f, (rect.top + rect.bottom) / 2.0f);
}
