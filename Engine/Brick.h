#pragma once
#include"Ball.h"

class Brick
{
private:
	Rect rect;
	Color c;
	bool isCollided = false;
public:
	Brick() = default;
	Brick(Rect rect, Color c);
	void Draw(Graphics& gfx)const;
	bool BallCollision(Ball& ball);
};