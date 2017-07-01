#include "Vec2.h"
#include<cmath>

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator+(const Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 & Vec2::operator+=(const Vec2 & rhs)
{
	// TODO: insert return statement here
	*this = *this + rhs;
	return *this;
}

void Vec2::DrawVector(Graphics & gfx) const
{
	gfx.PutPixel(int(x), int(y), Colors::White);
}

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	// TODO: insert return statement here
	*this = *this - rhs;
	return *this;
}

float Vec2::MagnitudeSq() const
{
	return x*x + y*y;
}

float Vec2::Magnitude() const
{
	float lengthSq = MagnitudeSq();
	return sqrt(lengthSq);
}

Vec2 Vec2::Normalised()
{
	float magnitude = Magnitude();
	return Vec2(x / magnitude, y / magnitude);
}

Vec2 Vec2::operator-(const Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}
