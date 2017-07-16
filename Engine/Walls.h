#pragma once
#include"Rect.h"

class Walls
{
private:
	Rect rect;
	float width;
	static constexpr Color c = Colors::Red;
public:
	Walls(Rect rect,float width);
	void Draw(Graphics& gfx)const;
	Rect GetRect()const;
};