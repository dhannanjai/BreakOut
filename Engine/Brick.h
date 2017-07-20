#pragma once
#include"Ball.h"
#include"Beveler.h"

class Brick
{
private:
	static constexpr int padding = 1;
	static constexpr int bevelSize = 5;

	Rect rect;
	Beveler bevel;
	bool hasCollided;
	
public:
	Brick() = default;
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx)const;
	bool BallCollision(const Ball& ball)const;
	float CalculateDistanceFromBall(const Ball& ball)const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter()const;
	Rect GetRect()const;
};