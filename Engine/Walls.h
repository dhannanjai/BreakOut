#pragma once
#include"Beveler.h"

class Walls
{
private:
	Rect rect;
	float width;
	Beveler bevel;
public:
	Walls(Rect rect,float width , Color C);
	void Draw(Graphics& gfx)const;
	const Rect& GetRect()const;
};