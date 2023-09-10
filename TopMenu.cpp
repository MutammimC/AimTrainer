#include "TopMenu.h"

using namespace std;


int TopMenu::Get_Menu_Width() const
{
	return Menu_Width;
}
void TopMenu::Set_Menu_Width(int Input_Width)
{
	Menu_Width = Input_Width;
}


int TopMenu::Get_Menu_Height() const
{
	return Menu_Height;
}
void TopMenu::Set_Menu_Height(int Input_Height)
{
	Menu_Height = Input_Height;
}


void TopMenu::Display_Menu()
{
	DrawRectangle(0, 0, Menu_Width, Menu_Height, DARKGRAY);
}

void TopMenu::Display_FPS(int pos_x, int pos_y)
{
	DrawFPS(pos_x, pos_y);
}

void TopMenu::Display_Points(int points)
{
	DrawText("Points :", 50, 50, 50, WHITE);
	DrawText(TextFormat("%i", points), 255, 50, 50, WHITE);
}