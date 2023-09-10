#include "Enemy.h"



int Enemy::Get_Rectangle_Width() const
{
	return Rectangle_Width;
}

void Enemy::Set_Rectangle_Width(int Width)
{
	Rectangle_Width = Width;
}
int Enemy::Get_Rectangle_Height() const
{
	return Rectangle_Height;
}

void Enemy::Set_Rectangle_Height(int Height)
{
	Rectangle_Height = Height;
}

void Enemy::Draw(int Input_Rectangle_x, int Input_Rectangle_y, int Input_Width, int Input_Height)
{
	DrawRectangle(Input_Rectangle_x, Input_Rectangle_y, Input_Width, Input_Height, RED);
	this->Rectangle_x = Input_Rectangle_x;
	this->Rectangle_y = Input_Rectangle_y;
	this->Rectangle_Width = Input_Width;
	this->Rectangle_Height = Input_Height;
}

bool Enemy::Is_Mouse_On_Enemy(int Mouse_Position_x, int Mouse_Position_y)
{
	if ((Mouse_Position_x < Rectangle_Width + Rectangle_x) && (Mouse_Position_x > Rectangle_x) && (Mouse_Position_y < Rectangle_Height + Rectangle_y) && (Mouse_Position_y > Rectangle_y))
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Enemy::Update()
{
	//When movement is added
}