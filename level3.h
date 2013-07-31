#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include "blockgenerator.h"

struct Level3 : public BlockGenerator
{
	Block* makeBlock();
};

#endif