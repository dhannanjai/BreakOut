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
	walls(Rect(10.0f, Graphics::ScreenHeight - 10.0f, 10.0f, Graphics::ScreenWidth - 10.0f), 10.0f),
	ball(Vec2(200,300),Vec2(-300,-300)),
	pad(Vec2(350, 400), padWidth, padHeight)
{
	Color color[4] = {Colors::Blue,Colors::Yellow , Colors::Green,Colors::Cyan};
	Vec2 topLeft(40.0f, 40.0f);
	
	for (size_t r = 0; r < brickRows; r++)
		for (size_t c = 0; c < brickCols; c++)
		{
			Vec2 point = topLeft + Vec2(c*brickWidth, r*brickHeight);
			size_t index = r*brickCols + c;
			int c_index = index % 4;
			bricks[index] = Brick(
									Rect(point, point + Vec2(brickWidth, brickHeight)),
									color[c_index]
								);
		}
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
	pad.DoWallCollision(walls.GetRect());
	
	
	ball.DoWallCollision(walls.GetRect());

	for (int i = 0; i < totalBricks; i++)
		bricks[i].BallCollision(ball);

	ball.DoPaddleCollision(pad);
}

void Game::ComposeFrame()
{
	for (auto brick : bricks)
	{
		brick.Draw(gfx);
	}
	ball.Draw(gfx);
	pad.Draw(gfx);
	walls.Draw(gfx);
}
