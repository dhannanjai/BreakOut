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
	walls(Graphics::GetScreenRect().GetExpanded(-40.0f), 40.0f, wallColor),
	ball(Graphics::GetScreenRect().GetCenter(), Vec2(-0.5f, -0.6f)),
	pad(Vec2(350, 500), padWidth, padHeight),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	soundNotStarted(L"Sounds\\ready.wav"),
	soundDead(L"Sounds\\fart.wav")
{
	const Vec2 gridTopLeft(walls.GetRect().left + leftSpace, walls.GetRect().top + topSpace);


	for (size_t r = 0; r < brickRows; r++)
		for (size_t c = 0; c < brickCols; c++)
		{
			Vec2 point = gridTopLeft + Vec2(c*brickWidth, r*brickHeight);
			size_t index = r*brickCols + c;
			int c_index = index % 4;
			bricks[index] = Brick(
									Rect(point, point + Vec2(brickWidth, brickHeight)),
									brickColors[c_index]
								);
		}
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	
	//here is where the gameState determines the flow of the game.
	switch (gameState)
	{
	case NotStarted:
		StateNotStarted();
		break;
	case Playing:
		StatePlaying();
		break;
	case Dead:
		StateDead();
		break;
	}

	gfx.EndFrame();
}

void Game::StateNotStarted()
{
	SpriteCodex::DrawTitle(Graphics::GetScreenRect().GetCenter(), gfx);
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		soundNotStarted.Play();
		
		gameState = Playing;
		ft = FrameTimer();
	}
}

void Game::DrawReady(float timeElapsed)
{
	readyScreenTime -= timeElapsed;
	SpriteCodex::DrawReady(Graphics::GetScreenRect().GetCenter(), gfx);
	if (readyScreenTime <= 0.0f)
		readyScreenDrawn = false;
}

void Game::StatePlaying()
{
	float timeElapsed = ft.Mark();
	if (readyScreenDrawn == true)
	{
		DrawReady(timeElapsed);
	}
	else
	{
		while (timeElapsed)
		{
			const float  dt = std::min(0.0025f, timeElapsed);
			UpdateModel(dt);
			timeElapsed -= dt;
		}
		ComposeFrame();
	}
}

void Game::StateDead()
{
	if (soundDeadplayed == false)
	{
		soundDead.Play();
		soundDeadplayed = true;
	}
	
	SpriteCodex::DrawGameOver(Graphics::GetScreenRect().GetCenter(), gfx);
}

void Game::UpdateModel(float dt)
{

	ball.update(dt);

	pad.GetInput(wnd.kbd, dt);
	pad.DoWallCollision(walls.GetRect());
	
	if (ball.CheckWallCollision(walls.GetRect()) == true)
	{
		gameState = ball.DoWallCollision(walls.GetRect());
		if(gameState == Playing)
			soundBrick.Play(1.0f, 0.1f);
	}
	
	
#pragma region Brick_Collision _with_Ball 
	short closestBrickIndex;
	bool collisionOccured = false;
	float minDistanceSquared;
	for (int i = 0; i < totalBricks; i++)
	{
		if (bricks[i].BallCollision(ball))
		{
			float currentDistanceSq = bricks[i].CalculateDistanceFromBall(ball);
			if (collisionOccured == false)
			{
				collisionOccured = true;
				closestBrickIndex = i;
				minDistanceSquared = currentDistanceSq;
			}

			else if (minDistanceSquared > currentDistanceSq)
			{
				minDistanceSquared = currentDistanceSq;
				closestBrickIndex = i;
			}
		}
	}
	if (collisionOccured == true)
	{
		bricks[closestBrickIndex].ExecuteBallCollision(ball);
		soundBrick.Play(1.0f, 0.1f);
	}
#pragma endregion

	if (pad.DoBallCollision(ball))
	soundPad.Play(1.0f, 0.1f);
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
