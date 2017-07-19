#pragma once
#include"Rect.h"

class Beveler
{
private:
	static constexpr float leftfactor = 1.10f;
	static constexpr float topfactor = 0.93f;
	static constexpr float bottomfactor = 0.80f;
	static constexpr float rightfactor = 0.65f;

	Color baseColor;
	Color topColor;
	Color bottomColor;
	Color leftColor;
	Color rightColor;

public:
	Beveler() = default;
	Beveler(const Color & baseColor);
	void DrawBevelInner(const Rect& rect, int size, Graphics& gfx)const;
	void DrawBevelOuter(const Rect& rect, int size, Graphics& gfx)const;
	void DrawBeveledBrick(const Rect& rect, int bevelSize, Graphics& gfx)const;
	void DrawBeveledFrame(const Rect & rect, int bevelSize, Graphics & gfx)const;
	void SetBaseColor(const Color& Basecolor);
};