#include<iostream>
#include<fstream>
#include "raylib.h"
#include<vector>

using namespace std;

class GameData
{
	
	private:
		float Current_Points;
		float Current_Time;
		int InputToFileCount;
		string FileData;
	vector<string>Points;
	vector<string>Times;
	vector<string>Averages;
	float AveragePointsPerSecond;

public:
	GameData(int UserPoints, int UserTime);
	void InputToFile();

	int GetPoints() const;
	int GetTimes() const;

	void Set_Current_Points(int UserPoints);
	void Set_Current_Time(int UserTime);

	void InputVectorValues();

	float GetPointsPerSecond() const;

	
};
