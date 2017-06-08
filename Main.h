#ifndef _MAIN_H
#define _MAIN_H

//farword declaration
class Manhatan;
class EmptyBlock;
class Main
{
public:
	int CurrentState[3][3] = { 8,7,6,5,4,3,2,1,0 };// to store the start or current state

	int GoalState[3][3];  // the goal state

	int static Hueristic;		// to decide the move ob the basis of min imu  hueristic


								//Methods	

	void DisplayPuzzle(int[][3]);			// to display the puzzle at any instant of time

	void PrepareGoalState();
	bool IsPresent(int);
	bool IsGoalState(int[][3]);
	void InitialState();


	Main();
	~Main();
};

#endif // !_MAIN_H