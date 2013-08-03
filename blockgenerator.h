#ifndef __BLOCKGENERATOR_H__
#define __BLOCKGENERATOR_H__
#include "i.h"
#include "j.h"
#include "l.h"
#include "o.h"
#include "s.h"
#include "z.h"
#include "t.h"

struct BlockGenerator
{
	virtual Block* makeBlock() = 0;
	static Block* makeBlock(char type, int level);
	virtual ~BlockGenerator() {}
};

#endif