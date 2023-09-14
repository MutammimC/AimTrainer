#include "raylib.h"
#include <string>

using namespace std;

class TopMenu
{
private:
	int Menu_Width = 1920;
	int Menu_Height = 216; // 20%
	string Points_Text = "Points";

public:
	int Get_Menu_Width() const;
	void Set_Menu_Width(int Input_Width);

	int Get_Menu_Height() const;
	void Set_Menu_Height(int Input_Height);


	void Display_Menu();
	void Display_FPS_And_Time(int pos_x, int pos_y, int Time);
	
	void Display_Points(int points);
};