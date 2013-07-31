#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "blockgenerator.h"

struct Level2 : public BlockGenerator
{
	Block* makeBlock();
};

#endif