#include <iostream>
#include <time.h>
#include <Windows.h>
#include "drawing.h"
using namespace std;
using namespace Draw;

#define circleCount 100
#define spawnRate 10

void main()
{
	Vector2 v2[circleCount];
	srand((unsigned)time(new time_t));

	Vector2 pos = { 200,200 };

	for (int i = 0; i < 100; i++)
	{
		//drawRectangle(pos, 100, 100, RGB(0,0,0));
		pos.x++;
		drawRectangle(pos, 100, 100);
		//Sleep(spawnRate);
	}

	std::cin.ignore();
}