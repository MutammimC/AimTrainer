#include "raylib.h"
#include <cstdlib>
 

class Enemy
{
private:
	int Rectangle_x = 0;
	int Rectangle_y = 0;
	int Rectangle_Width = 100;
	int Rectangle_Height = 100;

public:

	int Get_Rectangle_Width() const;
	void Set_Rectangle_Width(int Width);
	int Get_Rectangle_Height() const;
	void Set_Rectangle_Height(int Height);
	void Draw(int x, int y, int Input_Width, int Input_Height);
	bool Is_Mouse_On_Enemy(int Mouse_Position_x, int Mouse_Position_y);
	void Update();
	
};