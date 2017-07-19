#pragma once

#include"Paddle.h"

class Ball
{
private:
	Vec2 center;
	Vec2 dir;
	float speed = 400.0f;
	float radius = 7.0f;
	static constexpr float exitXfactor = 0.045f;
public:
	Ball(Vec2 center, Vec2 dir);
	void Draw(Graphics& gfx)const;
	void update(float dt);
	void ReboundX();
	void ReboundY();
	Rect GetRect()const;
	Vec2 Getcenter()const;
	Vec2 GetVelocity()const;
	void SetDirection(const Vec2& dir);

	bool DoWallCollision(const Rect& wall);
	bool DoPaddleCollision(const Paddle& pad);
	
};