#include "Walls.h"
#include<assert.h>

Walls::Walls(Rect rect, float width , Color c)
	:
	rect(rect),
	width(width/2),
	bevel(c)
{
	assert(rect.GetExpanded(width).IsContainedBy(Graphics::GetScreenRect()));
	assert(int(width) % 2 == 0);
}

void Walls::Draw(Graphics & gfx) const
{
	bevel.DrawBeveledFrame(rect.GetExpanded(width), width/2, gfx);
}

const Rect& Walls::GetRect() const
{
	return rect;
}
