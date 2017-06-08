#ifndef _EMPTYBLOCK_H
#define _EMPTYBLOCK_H

#include "Main.h"
class EmptyBlock : public Main
{
public:

	int Empty_I;
	int Empty_J;
	bool FindEmptyBlock(int[][3]);
	EmptyBlock();
	virtual ~EmptyBlock();
};

#endif // !_EMPTYBLOCK_H