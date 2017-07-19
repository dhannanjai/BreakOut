#pragma once
#include"Graphics.h"

class Ball
{
private:
	Vec2 center;
	Vec2 dir;
	float speed = 400.0f;
	float radius = 7.0f;
	
public:
	Ball(Vec2 center, Vec2 dir);
	
	void update(float dt);
	void ReboundX();
	void ReboundY();
	void SetDirection(const Vec2& dir);
	void SetCenter(const Vec2& center);
	bool DoWallCollision(const Rect & wall);

	void Draw(Graphics& gfx)const;
	Rect GetRect()const;
	Vec2 Getcenter()const;
	Vec2 GetVelocity()const;

};