#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <string>
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

struct Level
{
	static BlockGenerator* makeBlockGenerator(int level, std::string file="seqeunce.txt");
};

#endif