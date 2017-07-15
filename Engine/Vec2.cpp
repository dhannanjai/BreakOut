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

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	// TODO: insert return statement here
	*this = *this - rhs;
	return *this;
}

Vec2 Vec2::operator*(const float f) const
{
	return Vec2(x*f, y*f);
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
