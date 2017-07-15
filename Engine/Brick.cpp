#include "Brick.h"

Brick::Brick(Rect rect, Color c)
	:
	rect(rect),
	c(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	rect.Draw(gfx, c);
}
