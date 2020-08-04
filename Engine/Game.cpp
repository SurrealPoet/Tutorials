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
#include "Graphics.h"
#include "Mouse.h"

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

void Game::UpdateModel()
{
	moveBox();
	
}

void Game::ComposeFrame()
{
	crossHairs(400, 300);
	Rectangle(20, 20, 20, 20, 255, 255, 255);
}

void Game::Rectangle(int x0, int x1, int y0, int y1, int r, int g, int b)
{
	for (x0 = 0; x0 < x1; ++x0)
	{
		for (y0 = 0; y0 < y1; ++y0)
		{
			gfx.PutPixel( x + x0 , y + y0, 255, 255, 255);
		}
	}
}

void Game:: moveBox()
{
	if (wnd.kbd.KeyIsPressed( VK_UP ) || wnd.kbd.KeyIsPressed( 0x57 ))
	{
		y += -1;
	}
	if (wnd.kbd.KeyIsPressed( VK_DOWN ) || wnd.kbd.KeyIsPressed( 0x53 ))
	{
		y += 1;
	}if (wnd.kbd.KeyIsPressed( VK_LEFT ) || wnd.kbd.KeyIsPressed( 0x41 ))
	{
		x += -1;
	}if (wnd.kbd.KeyIsPressed( VK_RIGHT ) || wnd.kbd.KeyIsPressed( 0x44 ))
	{
		x += 1;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (x + 20 > Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 20;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y + 20 > Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 20;
	}
}

void Game::crossHairs( int crossX, int crossY )
{
	gfx.PutPixel(crossX + 1, crossY, 255, 255, 255);
	gfx.PutPixel(crossX + 2, crossY, 255, 255, 255);
	gfx.PutPixel(crossX + 3, crossY, 255, 255, 255);
	gfx.PutPixel(crossX - 1, crossY, 255, 255, 255);
	gfx.PutPixel(crossX - 2, crossY, 255, 255, 255);
	gfx.PutPixel(crossX - 3, crossY, 255, 255, 255);
	gfx.PutPixel(crossX, crossY + 1, 255, 255, 255);
	gfx.PutPixel(crossX, crossY + 2, 255, 255, 255);
	gfx.PutPixel(crossX, crossY + 3, 255, 255, 255);
	gfx.PutPixel(crossX, crossY - 1, 255, 255, 255);
	gfx.PutPixel(crossX, crossY - 2, 255, 255, 255);
	gfx.PutPixel(crossX, crossY - 3, 255, 255, 255);
}