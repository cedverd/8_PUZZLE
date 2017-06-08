#include "Main.h"
#include<iostream>
#include<vector>

Main::Main()
{
}


Main::~Main()
{
}

void Main::DisplayPuzzle(int State[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (State[i][j] != 0)
				std::cout << " " << State[i][j];
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
}
void Main::PrepareGoalState()
{
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->GoalState[i][j] = count++;
		}
	}
	this->GoalState[2][2] = 0;

	std::cout << "\n*****************************************";
	std::cout << " \nthe Goal State :\n";
	DisplayPuzzle(GoalState);
	std::cout << "\n*****************************************\n";
}

bool Main::IsGoalState(int CurrentState[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (CurrentState[i][j] != this->GoalState[i][j])
				return false;
		}
	}
	return true;
}

void Main::InitialState()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3;)
		{
			int range = 9;
			int num = rand() % range + 0;
			std::cout << num << std::endl;
			//if(this->IsPresent(num) == false)
			//{ 
			this->CurrentState[i][j] = num;

			//	}
			j++;
		}
	}
	std::cout << "*********************************";
	std::cout << "\nthe initial state is:\n";
	this->DisplayPuzzle(CurrentState);
}

bool Main::IsPresent(int Search_Num)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3;)
		{
			if (this->CurrentState[i][j] == Search_Num)
			{
				return	true;
			}
		}
		return false;
	}
}