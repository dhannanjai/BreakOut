#pragma once
#include"Ball.h"

class Brick
{
private:
	Rect rect;
	Color c;
	bool hasCollided;
	static constexpr int padding = 1;
public:
	Brick() = default;
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx)const;
	bool BallCollision(const Ball& ball)const;
	float CalculateDistanceFromBall(const Ball& ball)const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter()const;
};