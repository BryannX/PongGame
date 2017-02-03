/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void Paddle(int x, int y, int red, int green, int blue);
	void Paddle2(int x, int y, int red, int green, int blue);
	void Ball(int x, int y, int red, int green, int blue);

	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/

	//PADDLE ONE
	int posx = 10;
	int posy = 300;
	int velocx = 0;
	int velocy = 0;

	//PADDLE TWO
	int posx2 = gfx.ScreenWidth - 10;
	int posy2 = 300;
	int velocx2 = 0;
	int velocy2 = 0;

	//BALL
	int ballx = 400;
	int bally = 300;
	int ballvx = 10;
	int ballvy = 0;

	int gb = 255; // green blue
	int rb = 255; // red blue
	bool inhibitorLeft = false;
	bool inhibitorRight = false;
	bool inhibitorTop = false;// Pong game
	bool inhibitorBottom = false;// Pong game
	bool inhibitorTop2 = false;
	bool inhibitorBottom2 = false;
	bool controlIsPressed = false;

};