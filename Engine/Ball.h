#pragma once

#include"Rect.h"

class Ball
{
private:
	Rect rect;
	Vec2 center;
	Vec2 vel;
	float radius = 7.0f;
public:
	Ball(Vec2 center, Vec2 vel);
	void Draw(Graphics& gfx)const;
	void update(float dt);
};