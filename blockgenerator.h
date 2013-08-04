#ifndef __BLOCKGENERATOR_H__
#define __BLOCKGENERATOR_H__
#include "block.h"
#include "o.h"

struct BlockGenerator
{
	virtual Block* makeBlock() = 0;
	virtual ~BlockGenerator() {}
};

#endif