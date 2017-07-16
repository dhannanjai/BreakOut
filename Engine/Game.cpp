/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	walls(Rect(0, Graphics::ScreenHeight, 0, Graphics::ScreenWidth)),
	brick(Rect(Vec2(50,100),brickWidth,brickHeight),Colors::Cyan),
	ball(Vec2(200,300),Vec2(-300,-300)),
	pad(Vec2(350, 400), padWidth, padHeight)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	float timeElapsed = ft.Mark();
	while (timeElapsed)
	{
		const float  dt = std::min(0.0025f, timeElapsed);
		UpdateModel(dt);
		timeElapsed -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{

	ball.update(dt);

	pad.GetInput(wnd.kbd, dt);
	pad.DoWallCollision(walls);
	
	
	ball.DoWallCollision(walls);

	brick.BallCollision(ball);

	ball.DoPaddleCollision(pad);
}

void Game::ComposeFrame()
{
	brick.Draw(gfx);
	ball.Draw(gfx);
	pad.Draw(gfx);
}
