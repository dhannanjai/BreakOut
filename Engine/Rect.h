#pragma once
#include"Vec2.h"

class Rect
{
public:
	float top;
	float bottom;
	float left;
	float right;
	/*
	Here's the deal, you have to understand that these float values are actually reflecting the distances of a particular edge from the origin.
	For eg:- t = 100,l = 50,r = 150,b = 200
	then:
	topleft point is (50,100)
	bottomright is (150,200)
	You get the idea!
	*/
public:
	Rect() = default;
	Rect(float top, float bottom, float left, float right);
	Rect(const Vec2 topLeft, const  Vec2 bottomRight);
	Rect(const Vec2 topLeft, float width, float height);
	Rect(const Vec2 center, float radius);
	bool IsOverLappingWith(const Rect& rect)const;
	bool IsContainedBy(const Rect& rect)const;
	
	Rect GetExpanded(float offset)const;
};