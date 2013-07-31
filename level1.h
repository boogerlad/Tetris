#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "blockgenerator.h"

struct Level1 : public BlockGenerator
{
	Block* makeBlock();
};

#endif