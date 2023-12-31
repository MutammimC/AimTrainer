#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include<time.h>

#include "TopMenu.h"
#include "enemy.h"
#include "GameData.h"


using namespace std;



int main()
	{

	
		double spawnTimer = 0.0;
		double spawnInterval = 0.85;

		const int ScreenWidth = 1920;
		const int ScreenHeight = 1080;

		int Rectangle_x;
		int Rectangle_y;

		const int Rectangle_Width = 100;
		const int Rectangle_Height = 100;
		int Point_Counter = 0;

		int Total_Time_Passed;

		InitWindow(ScreenWidth, ScreenHeight, "AimTrainer");
		InitAudioDevice();
		SetTargetFPS(60);


		Enemy Enemy1;
		TopMenu TopMenu;


		auto startTime = chrono::high_resolution_clock::now();
		double delayInSeconds = 1.0;

		Sound Ding;
		Ding = LoadSound("AimTrainer_Resources/4537996643401728.wav");
		

		do
		{
			
			BeginDrawing();
			double deltaTime = GetFrameTime();
			spawnTimer += deltaTime;

			Rectangle_x = (rand() % (GetScreenWidth() - Enemy1.Get_Rectangle_Width())) + 1;
			Rectangle_y = (rand() % (GetScreenHeight() - Enemy1.Get_Rectangle_Height()  - TopMenu.Get_Menu_Height())) + TopMenu.Get_Menu_Height();
			
			TopMenu.Display_Menu();
			TopMenu.Display_FPS_And_Time(25, 25, GetTime());
			TopMenu.Display_Points(Point_Counter);


			if (spawnTimer >= spawnInterval) 
			{
				ClearBackground(BLACK);
				Enemy1.Draw(Rectangle_x, Rectangle_y, Rectangle_Width, Rectangle_Height);
				spawnTimer = 0.0;
				// Add an average points/time 
			}


			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && Enemy1.Is_Mouse_On_Enemy(GetMouseX(), GetMouseY()))
			{
				SwapScreenBuffer();
				PlaySound(Ding);
				Point_Counter += 1;

				cout << "You gained a point!" << endl;
				ClearBackground(BLACK);

				Enemy1.Draw2(Enemy1.Get_Rectangle_x(), Enemy1.Get_Rectangle_y(), Rectangle_Width, Rectangle_Height);
				
				Enemy1.Set_Rectangle_Height(0);
				Enemy1.Set_Rectangle_Width(0);
				//Maybe Add a texture?
				
			}
			
			EndDrawing();
		} while (!WindowShouldClose());
		Total_Time_Passed = GetTime();
		
		
		cout << "You got " << Point_Counter << " Points in " << Total_Time_Passed << " Seconds" << endl;
//Do Game Data Stuff
		GameData GameData(Point_Counter, Total_Time_Passed);

//Ending any raylib operations
		UnloadSound(Ding);
		CloseAudioDevice();
		CloseWindow();
		return 0;
	}
