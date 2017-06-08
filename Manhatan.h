#ifndef _MANHATAN_H
#define _MANHATAN_H
#include<vector>
#include "EmptyBlock.h"
class Manhatan : public EmptyBlock
{
public:
	int ManhatanState[3][3];
	int I = 0;	// to store the ROW index of the goal state
	int J = 0;	// to store the COLUMN index of the goal state
	int CalculateHeuristic();
	int ElementManhatan(int Element, int i, int j);
	void ManhatanDistance(int State[][3]);
	bool Search(int);
	int HueristicOnMove(int heu, int Element, int, int);

	Manhatan();
	virtual ~Manhatan();
	struct Move
	{
		int x = 0;
		int y = 0;
	}FinalMove;

	void PrimaryCornerMoves();   // sum of empty block index is '0' Or '4'
	void MoveAboveDiagonal();	// sum of empty block index is 1
	void MoveBelowDiagonal();	// sum of empty block index is 3
	void MoveOnMiddle();			// when empty block indices are 1
	void SecndaryCornerMoves();	// sum of empty block index is 2
	void GetMove();
	void SetMove();
	void Display();

	//int random(int min ,int max);

};


/*
1 2 3
4 5 6
7 8 9
*/
#endif // !_MANHATAN_H