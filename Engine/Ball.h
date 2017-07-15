#pragma once

#include"Paddle.h"

class Ball
{
private:
	Vec2 center;
	Vec2 vel;
	float radius = 7.0f;
public:
	Ball(Vec2 center, Vec2 vel);
	void Draw(Graphics& gfx)const;
	void update(float dt);
	void DoWallCollision(const Rect& wall);
	void ReboundX();
	void ReboundY();
	Rect GetRect()const;

	void DoPaddleCollision(const Paddle& pad);
};