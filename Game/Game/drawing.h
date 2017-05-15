#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

typedef struct
{
	int x, y;
}Vector2;

static enum AnchorPosition
{
	TopLeft = 1,
	TopRight = 2,
	BottomLeft = 3,
	BottomRight = 4
};

#define PI 3.14

namespace Draw
{
	double lenghtdir_x(int len, int dir)
	{
		return cos(dir * PI / 180) * len;
	}

	double lenghtdir_y(int len, int dir)
	{
		return sin(dir * PI / 180) * len;
	}

	HDC device = GetDC(GetConsoleWindow());
	COLORREF c_blue = RGB(0, 0, 255);
	COLORREF c_rot = RGB(255, 0, 0);
	COLORREF c_gruen = RGB(0, 255, 0);
	COLORREF c_black = RGB(0, 0, 0);
	COLORREF c_random;	

	void drawRandomColoredCircle(Vector2 position, int radius)
	{
		switch (rand() % 4)
		{
		case 1:
		{
			c_random = c_rot;
		}break;

		case 2:
		{
			c_random = c_gruen;
		}break;

		case 3:
		{
			c_random = c_blue;
		}break;
		}

		for (int x = 0; x < radius; x++)
		{		
			for (unsigned int i = 0; i < 360; i++)
			{			
				SetPixel(device, position.x + lenghtdir_x(radius , i), position.y + lenghtdir_y(radius, i), c_random);
			}
		}
	}

	void drawCircle(Vector2 position, int radius, COLORREF color)
	{
		for (int x = 0; x < radius; x++)
		{
			for (unsigned int i = 0; i < 360; i++)
			{
				SetPixel(device, position.x + lenghtdir_x(radius, i), position.y + lenghtdir_y(radius, i), color);
			}
		}
	}

	void antiDrawCircle(Vector2 position, int radius)
	{
		for (unsigned int i = 360; i > 0; i--)
		{
			SetPixel(device, position.x + lenghtdir_x(radius, i), position.y + lenghtdir_y(radius, i), c_black);
		}
	}

	void drawRectangle(Vector2 position, int width, int height, COLORREF color, AnchorPosition anchorPosition)
	{
		switch (anchorPosition)
		{
		case TopLeft:
			for (int i = position.x; i < width + position.x; i++)
			{
				SetPixel(device, i, position.y, color);
				SetPixel(device, i, position.y - height, color);
			}
			for (int i = position.y-height; i < position.y; i++)
			{
				SetPixel(device, position.x, i, color);
				SetPixel(device, position.x + width, i, color);
			}
			break;
		case TopRight:
			break;
		case BottomLeft:
			break;
		case BottomRight:
			break;
		default:
			break;
		}
	}

	void drawRectangle(Vector2 position, int width, int height)
	{
		drawRectangle(position, width, height, RGB(255, 255, 255), AnchorPosition::TopLeft);
	}

	void drawRectangle(Vector2 position, int width, int height, AnchorPosition anchorPosition)
	{
		drawRectangle(position, width, height, RGB(255, 255, 255), anchorPosition);
	}

	void drawRectangle(Vector2 position, int width, int height, COLORREF color)
	{
		drawRectangle(position, width, height, color, AnchorPosition::TopLeft);
	}
}