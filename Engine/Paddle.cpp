#include "Paddle.h"

Paddle::Paddle(Vec2 pos, float width, float height)
{
	this->pos = pos;
	this->height = height;
	this->width = width;
}

void Paddle::GetInput(Keyboard & kbd ,float dt)
{

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed*dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed*dt;
	}
}

void Paddle::Draw(Graphics & gfx) const
{
	Rect rect = GetRect();
	rect.Draw(gfx, c);
	rect.left += wingPadding;
	rect.right -= wingPadding;
	rect.Draw(gfx, wingColor);
}

Rect Paddle::GetRect() const
{
	return Rect(pos - Vec2(width / 2, height / 2), width, height);
}

void Paddle::DoWallCollision(const Rect & walls)
{
	Rect rect = GetRect();
	if (rect.left < walls.left)
		pos.x += (walls.left - rect.left);

	else if (rect.right > walls.right)
		pos.x += (walls.right - rect.right);

	if (rect.top < walls.top)
		pos.y += (walls.top - rect.top);
	else if (rect.bottom > walls.bottom)
		pos.y += (walls.bottom - rect.bottom);
}
