#pragma once

class Vec2
{
public:
		float x;
		float y;
public:
	Vec2(float x, float y);
	Vec2() = default;
	Vec2 operator+(const Vec2& rhs)const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs)const;
	Vec2& operator-=(const Vec2& rhs);
	Vec2 operator*(const float f)const;

	float MagnitudeSq()const;
	float Magnitude()const;
	Vec2 Normalised();
};