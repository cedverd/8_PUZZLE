#include "EmptyBlock.h"
EmptyBlock::EmptyBlock()
{
}


EmptyBlock::~EmptyBlock()
{
}

bool EmptyBlock::FindEmptyBlock(int Start[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!Start[i][j])
			{
				this->Empty_I = i;
				this->Empty_J = j;
				return true;
			}
		}
	}
	return false;
}