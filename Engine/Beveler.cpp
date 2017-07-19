#include "Beveler.h"

Beveler::Beveler(const Color & baseColor)
{
	SetBaseColor(baseColor);
}

void Beveler::DrawBevelInner(const Rect & rect, int size, Graphics & gfx) const
{
	const int left = int(rect.left);
	const int right = int(rect.right);
	const int top = int(rect.top);
	const int bottom = int(rect.bottom);
	// left side bevel (corner,side,corner)
	gfx.DrawIsoRightTriBL(left, top + size, size, rightColor);
	gfx.DrawRect(left, top + size, left + size, bottom - size, rightColor);
	gfx.DrawIsoRightTriUL(left, bottom - size, size, rightColor);

	// top side bevel
	gfx.DrawIsoRightTriUR(left + size, top, size, bottomColor);
	gfx.DrawRect(left + size, top, right - size, top + size, bottomColor);
	gfx.DrawIsoRightTriUL(right - size, top, size, bottomColor);
	
	// right side bevel
	gfx.DrawIsoRightTriBR(right , top + size, size, leftColor);
	gfx.DrawRect(right - size, top + size, right, bottom - size, leftColor);
	gfx.DrawIsoRightTriUR(right, bottom - size, size, leftColor);

	// bottom side bevel
	gfx.DrawIsoRightTriBR(left + size , bottom , size, topColor);
	gfx.DrawRect(left + size, bottom - size, right - size, bottom, topColor);
	gfx.DrawIsoRightTriBL(right - size, bottom , size, topColor);
}

void Beveler::DrawBevelOuter(const Rect & rect, int size, Graphics & gfx) const
{
	const int left = int(rect.left);
	const int right = int(rect.right);
	const int top = int(rect.top);
	const int bottom = int(rect.bottom);

	// left side
	gfx.DrawIsoRightTriBL(left, top + size, size, leftColor);
	gfx.DrawRect(left, top + size, left + size, bottom - size, leftColor);
	gfx.DrawIsoRightTriUL(left, bottom - size, size, leftColor);

	//right side
	gfx.DrawIsoRightTriBR(right, top + size, size, rightColor);
	gfx.DrawRect(right - size, top + size, right, bottom - size, rightColor);
	gfx.DrawIsoRightTriUR(right, bottom - size, size, rightColor);

	//top side
	gfx.DrawIsoRightTriUR(left + size, top, size, topColor);
	gfx.DrawRect(left + size, top, right - size, top + size, topColor);
	gfx.DrawIsoRightTriUL(right - size, top, size, topColor);

	//bottom side
	gfx.DrawIsoRightTriBR(left + size, bottom, size, bottomColor);
	gfx.DrawRect(left + size, bottom - size, right - size, bottom, bottomColor);
	gfx.DrawIsoRightTriBL(right - size, bottom, size, bottomColor);
}

void Beveler::DrawBeveledBrick(const Rect & rect, int bevelSize, Graphics & gfx) const
{
	DrawBevelOuter(rect, bevelSize, gfx);
	Rect r = rect.GetExpanded(-float(bevelSize));
	r.Draw(gfx, baseColor);
}

void Beveler::DrawBeveledFrame(const Rect & rect, int bevelSize, Graphics & gfx)const
{
	DrawBevelOuter(rect, bevelSize, gfx);
	Rect r = rect.GetExpanded(-float(bevelSize));
	DrawBevelInner(r, bevelSize, gfx);
}

void Beveler::SetBaseColor(const Color & baseColor)
{
	this->baseColor = baseColor;
	topColor = Color
	(
		int(float(baseColor.GetR()) * topfactor),
		int(float(baseColor.GetG()) * topfactor),
		int(float(baseColor.GetB()) * topfactor)
	);

	bottomColor = Color
	(
		int(float(baseColor.GetR()) * bottomfactor),
		int(float(baseColor.GetG()) * bottomfactor),
		int(float(baseColor.GetB()) * bottomfactor)
	);

	leftColor = Color
	(
		int(float(baseColor.GetR()) * leftfactor),
		int(float(baseColor.GetG()) * leftfactor),
		int(float(baseColor.GetB()) * leftfactor)
	);

	rightColor = Color
	(
		int(float(baseColor.GetR()) * rightfactor),
		int(float(baseColor.GetG()) * rightfactor),
		int(float(baseColor.GetB()) * rightfactor)
	);

}


