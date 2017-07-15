#pragma once

#include"Rect.h"

class Ball
{
private:
	Rect rect;
	float radius = 7.0f;
	Color c;
public:
	Ball(Rect rect);
	void Draw(Graphics& gfx)const;
};