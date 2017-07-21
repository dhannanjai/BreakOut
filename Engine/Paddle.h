#pragma once

#include"Keyboard.h"
#include"Ball.h"

class Paddle
{
	float height, width;
	//Rect rect;
	
	Vec2 pos;
	float speed = 300;
	float wingPadding = 10.0f;

	static constexpr Color c = Colors::Yellow;
	static constexpr Color wingColor = Colors::Red;


	static constexpr float exitXfactorRatio = 0.045f;
	static constexpr float halfZoneWidthRatio = 0.2f;
	static constexpr float maxExitratio = 2.6f;

	const float halfZoneWidth;
	const float exitXfactor;
	const float fixedZoneExitX;
public:
	Paddle(Vec2 pos, float height, float width);
	void GetInput(Keyboard& kbd,float dt);
	void Draw(Graphics& gfx)const;
	Rect GetRect()const;
	void DoWallCollision(const Rect& walls);
	bool DoBallCollision(Ball& ball);
};