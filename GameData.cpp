#include "GameData.h"
#include <fstream>
#include <string>
#include <vector>
GameData::GameData(int UserPoints, int UserTime)
{
	Current_Points = UserPoints;
	Current_Time = UserTime;
	InputToFile();
}

void GameData::InputToFile()
{
	if (InputToFileCount < 1)
	{
		ofstream AimTrainerData("AimTrainerData.txt", ios::app); //Question why does iop::app keep file data from being overwritten?
		AimTrainerData << Current_Points << "\n" << Current_Time << "\n" << Current_Points / Current_Time << endl;
		AimTrainerData.close();
		InputToFileCount++;
		InputVectorValues();
	}
	else
	{
		cout << "Error" << " InputToFile() has been called more than once: " << InputToFileCount << endl;
	}
}

int GameData::GetPoints() const
{
	return 0; //Fix this
}

int GameData::GetTimes() const
{
	return 0; //Fix this
}

void GameData::Set_Current_Points(int UserPoints)
{
	Current_Points = UserPoints;
}

void GameData::Set_Current_Time(int UserTime)
{
	Current_Time = UserTime;
}


void GameData::InputVectorValues()
{

	int count = 0;
	string PlaceHolder;
	ifstream AimTrainerData("AimTrainerData.txt");
	while (AimTrainerData >> PlaceHolder)
	{
		switch (count)
		{
		case 0:
			Points.push_back(PlaceHolder);
			PlaceHolder = "";
			count++;
			//cout << "case 0:" << count << " " << PlaceHolder << endl;
			break;

		case 1:
			Times.push_back(PlaceHolder);
			PlaceHolder = "";
			count++;
			//cout << "case 1:" << count << " " << PlaceHolder << endl;
			break;

		case 2:
			Averages.push_back(PlaceHolder);
			PlaceHolder = "";
			count == 0;
			//cout << "case 2:" << count << " " << PlaceHolder << endl;
			break;

		default:
			cout << "Error: case values should only be between 0 and 1" << endl;
			break;

		}
	}
	AimTrainerData.close();
}