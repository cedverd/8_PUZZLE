#include "Manhatan.h"
#include<math.h>
#include<iostream>
#include<random>

Manhatan::Manhatan()
{
}


Manhatan::~Manhatan()
{
}

//public methods
int Manhatan::CalculateHeuristic()
{
	int hueristic = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			hueristic += this->ManhatanState[i][j];
		}
	}
	return hueristic;
}
int Manhatan::ElementManhatan(int Element, int i, int j)
{
	int m_Distance;
	if (Element)
	{
		Search(Element);
		m_Distance = abs((int)this->I - i) + abs((int)this->J - j);
		return m_Distance;
	}
	return -1;
}

bool Manhatan::Search(int Element)  // this function searches the values accoerding to the goal state and store the values of indices 
{
	if (Element)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Element == this->GoalState[i][j])
				{
					this->I = i;
					this->J = j;
					return true;
				}
			}
		}
	}
	return false;
}
void Manhatan::ManhatanDistance(int State[][3])    // to calculate the manhatan distance of the whole array / list
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->ManhatanState[i][j] = this->ElementManhatan(this->CurrentState[i][j], i, j);
		}
	}
	std::cout << "\nthe Manhatan Distances of the current State are\n";
	this->Display();
}

int Manhatan::HueristicOnMove(int H, int Element, int next_i, int next_j)
{
	H -= this->ManhatanState[next_i][next_j];
	H += this->ElementManhatan(Element, this->Empty_I, this->Empty_J);
	return H;
}
void Manhatan::PrimaryCornerMoves()
{
	if (this->Empty_I == 0)
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
		if (H1 < H2)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J + 1;
			this->Hueristic = H1;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I + 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H2;
			this->SetMove();
		}
	}
	else
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);
		if (H1 < H2)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			this->Hueristic = H1;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H2;
			this->SetMove();
		}
	}
}
void Manhatan::MoveAboveDiagonal()
{
	if (this->Empty_I == 0)
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
		int H3 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
		if (H1 < H2)
		{
			if (H1 < H3)
			{
				this->FinalMove.x = this->Empty_I;
				this->FinalMove.y = this->Empty_J + 1;
				Hueristic = H1;
				this->SetMove();
			}
			else
			{
				this->FinalMove.x = this->Empty_I;
				this->FinalMove.y = this->Empty_J - 1;
				Hueristic = H3;
				this->SetMove();
			}
		}
		else if (H2 < H3)
		{
			this->FinalMove.x = this->Empty_I + 1;
			this->FinalMove.y = this->Empty_J;
			Hueristic = H2;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			Hueristic = H3;
			this->SetMove();
		}
	}
	else
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
		int H3 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
		if (H1 < H2)
		{
			if (H1 < H3)
			{
				this->FinalMove.x = this->Empty_I - 1;
				this->FinalMove.y = this->Empty_J;
				Hueristic = H1;
				this->SetMove();
			}
		}
		else if (H2 < H3)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J + 1;
			Hueristic = H2;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I + 1;
			this->FinalMove.y = this->Empty_J;
			Hueristic = H3;
			this->SetMove();
		}
	}
}
void Manhatan::MoveBelowDiagonal()
{
	if (!this->Empty_I == 2)
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
		int H3 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);

		if (H1 < H2)
		{
			if (H1 < H3)
			{
				this->FinalMove.x = this->Empty_I + 1;
				this->FinalMove.y = this->Empty_J;
				this->Hueristic = H1;
				this->SetMove();
			}
			else
			{
				this->FinalMove.x = this->Empty_I - 1;
				this->FinalMove.y = this->Empty_J;
				this->Hueristic = H3;
				this->SetMove();
			}
		}
		else if (H2 < H3)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			this->Hueristic = H2;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H3;
			this->SetMove();
		}
	}
	else
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
		int H3 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);

		if (H1 < H2)
		{
			if (H1 < H3)
			{
				this->FinalMove.x = this->Empty_I;
				this->FinalMove.y = this->Empty_J + 1;
				this->Hueristic = H1;
				this->SetMove();
			}
			else
			{
				this->FinalMove.x = this->Empty_I - 1;
				this->FinalMove.y = this->Empty_J;
				this->Hueristic = H3;
				this->SetMove();
			}
		}
		else if (H2 < H3)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			this->Hueristic = H2;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H3;
			this->SetMove();
		}

	}
}
void Manhatan::MoveOnMiddle()
{
	int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
	int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
	int H3 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
	int H4 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);
	if (H1 < H2)
	{
		if (H1 < H3)
		{
			if (H1 < H4)
			{
				this->FinalMove.x = this->Empty_I;
				this->FinalMove.y = this->Empty_J + 1;
				this->Hueristic = H1;
				this->SetMove();
			}
			else
			{
				this->FinalMove.x = this->Empty_I - 1;
				this->FinalMove.y = this->Empty_J;
				this->Hueristic = H4;
				this->SetMove();

			}
		}
		else if (H3 < H4)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			this->Hueristic = H3;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H4;
			this->SetMove();
		}
	}
	else if (H2 < H3)
	{
		if (H2 < H4)
		{
			this->FinalMove.x = this->Empty_I + 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H2;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H4;
			this->SetMove();
		}
	}
	else if (H3 < H4)
	{
		this->FinalMove.x = this->Empty_I;
		this->FinalMove.y = this->Empty_J - 1;
		this->Hueristic = H3;
		this->SetMove();
	}
	else
	{
		this->FinalMove.x = this->Empty_I - 1;
		this->FinalMove.y = this->Empty_J;
		this->Hueristic = H4;
		this->SetMove();
	}
}
void Manhatan::SecndaryCornerMoves()
{
	if (this->Empty_I == 2)
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J + 1], this->Empty_I, this->Empty_J + 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I - 1][this->Empty_J], this->Empty_I - 1, this->Empty_J);
		if (H1 < H2)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J + 1;
			this->Hueristic = H1;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I - 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H2;
			this->SetMove();
		}
	}
	else
	{
		int H1 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I][this->Empty_J - 1], this->Empty_I, this->Empty_J - 1);
		int H2 = HueristicOnMove(Hueristic, CurrentState[this->Empty_I + 1][this->Empty_J], this->Empty_I + 1, this->Empty_J);
		if (H1 < H2)
		{
			this->FinalMove.x = this->Empty_I;
			this->FinalMove.y = this->Empty_J - 1;
			this->Hueristic = H1;
			this->SetMove();
		}
		else
		{
			this->FinalMove.x = this->Empty_I + 1;
			this->FinalMove.y = this->Empty_J;
			this->Hueristic = H2;
			this->SetMove();
		}
	}
}

void Manhatan::GetMove()
{
	switch (this->Empty_I + this->Empty_J)
	{
	case 0:
		this->PrimaryCornerMoves();
		break;
	case 1:
		this->MoveAboveDiagonal();
		break;
	case 2:
		if (this->Empty_I == this->Empty_J)
			this->MoveOnMiddle();
		else
			this->SecndaryCornerMoves();
		break;
	case 3:
		this->MoveBelowDiagonal();
		break;
	case 4:
		this->PrimaryCornerMoves();
		break;
	default:
		break;
	}
}
void Manhatan::SetMove()
{

	this->CurrentState[this->Empty_I][this->Empty_J] = this->CurrentState[this->FinalMove.x][this->FinalMove.y];
	this->Empty_I = this->FinalMove.x;
	this->Empty_J = this->FinalMove.y;
	DisplayPuzzle(CurrentState);
	if (!IsGoalState(CurrentState))
		this->GetMove();
}

//std::random_device rd;		//obtains a random number from hardware
//std::mt19937 eng(rd());		// seed the generator
//std::uniform_int_distribution<> distr(0, 8);	//defines the range

void Manhatan::Display()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//if (ManhatanState[i][j] != -1)
			std::cout << " " << ManhatanState[i][j];
			//else
			//	std::cout << "  ";
		}
		std::cout << std::endl;
	}
}