#include "Manhatan.h"
#include "EmptyBlock.h"
#include<iostream>
#include<conio.h>
#include <vector>
#include<random>
void Initialize();

int main()
{

	Manhatan* Game = new Manhatan();
	//int Manhatan::random(int min, int max)
	//{
	//	static bool first = true;
	//	if (first)
	//	{
	//		srand(time(NULL));
	//		first = false;
	//	}  
	//	return min + rand() % (max - min);
	//}
	Game->CurrentState[0][0] = 8;	Game->CurrentState[0][1] = 5;	Game->CurrentState[0][2] = 4;
	Game->CurrentState[1][0] = 1;	Game->CurrentState[1][1] = 3;	Game->CurrentState[1][2] = 6;
	Game->CurrentState[2][0] = 0;	Game->CurrentState[2][1] = 2;	Game->CurrentState[2][2] = 7;
	Game->PrepareGoalState();
	Game->DisplayPuzzle(Game->CurrentState);
	Game->ManhatanDistance(Game->CurrentState);
	Game->CalculateHeuristic();
	std::cout << Game->Hueristic;
	Game->GetMove();

	delete Game;
	_getch();
	return 0;

}

void Initialize(int array[][3])
{
	int count = 8;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; i < 3; i++)
		{
			array[i][j] = count--;
		}
	}
}
