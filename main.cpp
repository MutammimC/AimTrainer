#include "raylib.h"
#include <iostream>

int main()
{
	const int ScreenWidth = 1920;
	const int ScreenHeight = 1080;

	InitWindow(ScreenWidth, ScreenHeight, "AimTrainer");
	SetTargetFPS(60);

	do
	{
		BeginDrawing();

		EndDrawing();
	}while(WindowShouldClose() == false)
}