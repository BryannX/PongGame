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

															/******************
															*				  *
															*  PONG GAME	  *
															*			      *
															******************/

#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::Paddle(int x, int y, int red, int green, int blue)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		gfx.PutPixel(posx, posy + i, red, green, blue);
		gfx.PutPixel(-1 + posx, posy + i, red, green, blue);
		gfx.PutPixel(1 + posx, posy + i, red, green, blue);
		gfx.PutPixel(2 + posx, posy + i, red, green, blue);
		gfx.PutPixel(-2 + posx, posy + i, red, green, blue);
		gfx.PutPixel(3 + posx, posy + i, red, green, blue);
		gfx.PutPixel(-3 + posx, posy + i, red, green, blue);
		gfx.PutPixel(4 + posx, posy + i, red, green, blue);
		gfx.PutPixel(-4 + posx, posy + i, red, green, blue);
		gfx.PutPixel(5 + posx, posy + i, red, green, blue);
		gfx.PutPixel(-5 + posx, posy + i, red, green, blue);
	}
}

void Game::Paddle2(int x, int y, int red, int green, int blue)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		gfx.PutPixel(posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(-1 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(1 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(2 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(-2 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(3 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(-3 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(4 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(-4 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(5 + posx2, posy2 + i, red, green, blue);
		gfx.PutPixel(-5 + posx2, posy2 + i, red, green, blue);
	}
}

void Game::Ball(int x, int y, int red, int green, int blue)
{
	int i;
	int j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			gfx.PutPixel(i + x, j + y, red, green, blue);
		}
	}

}

void Game::UpdateModel()
{

														//CODE FOR PLAYER 1
	posx = posx + velocx;
	posy = posy + velocy;

	if (wnd.kbd.KeyIsPressed(0x41)) {
		if (inhibitorTop)
		{

		}
		else
		{
			posy = posy - 10;
			velocy = velocy - 8;
			inhibitorTop = true;
		}
	}
	else
	{
		inhibitorTop = false;
		if (!wnd.kbd.KeyIsPressed(0x5A))
		{
			velocy = 0;
		}
	}


	if (wnd.kbd.KeyIsPressed(0x5A)) {
		if (inhibitorBottom)
		{

		}
		else
		{
			posy = posy + 10;
			velocy = velocy + 8;
			inhibitorBottom = true;
		}
	}
	else
	{
		inhibitorBottom = false;
		if (!wnd.kbd.KeyIsPressed(0x41))
		{
			velocy = 0;
		}
	}







														//CODE FOR PLAYER 2

	posx2 = posx2 + velocx2;
	posy2 = posy2 + velocy2;


	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitorTop2)
		{

		}
		else
		{
			posy2 = posy2 - 10;
			velocy2 = velocy2 - 8;
			inhibitorTop2 = true;
		}
	}
	else
	{
		inhibitorTop2 = false;
		if (!wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			velocy2 = 0;
		}
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitorBottom2)
		{

		}
		else
		{
			posy2 = posy2 + 10;
			velocy2 = velocy2 + 8;
			inhibitorBottom2 = true;
		}
	}
	else
	{
		inhibitorBottom2 = false;
		if (!wnd.kbd.KeyIsPressed(VK_UP))
		{
			velocy2 = 0;
		}
	}


													//BOUNDARY CODE FOR THE PADDLES


	if (posy + 100 >= gfx.ScreenHeight)
	{
		posy = gfx.ScreenHeight - 101;
		velocy = 0;
	}
	if (posy <= 0)
	{
		posy = 1;
		velocy = 0;
	}

	if (posy2 + 100 >= gfx.ScreenHeight)
	{
		posy2 = gfx.ScreenHeight - 101;
		velocy2 = 0;
	}
	if (posy2 <= 0)
	{
		posy2 = 1;
		velocy2 = 0;
	}


														//BALL CODE AND LOGIC 

	ballx = ballx + ballvx;
	bally = bally + ballvy;

	/*CASES TO CODE FOR:
	1. WHEN THE BALL COLLIDES WITH THE PADDLES
		i. Middle
		ii. Near end
		iii. Far end;
	2. WHEN THE BALL COLLIDES WITH THE WALL
	3. WHEN THE BALL COLLIDES WITH ANY OF THE PLAYER'S ENDS.
	*/
	if (ballx - 9 <= posx) 
	{
		if (bally < posy + 100)
		{
			ballvx = 10;
		}
	}

	if (ballx + 9 >= posx2)
	{
		if (bally < posy2 + 100)
		{
			ballvx = 0;
		}
	}

	if (ballx >= gfx.ScreenWidth - 10)
	{
		ballvx = -10;
	}

	if (ballx <= 0)
	{
		ballvx = 10;
	}
}

void Game::ComposeFrame()
{
	Paddle(posx, posy, 255, 255, 255);
	Paddle2(posx2, posy2, 255, 255, 255);
	Ball(ballx, bally, 255, 255, 255);
}
