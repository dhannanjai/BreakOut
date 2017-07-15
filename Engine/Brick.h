#pragma once
#include"Rect.h"

class Brick
{
private:
	Rect rect;
	Color c;
public:
	Brick() = default;
	Brick(Rect rect, Color c);
	void Draw(Graphics& gfx)const;
};