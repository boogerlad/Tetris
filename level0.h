#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include <fstream>
#include <sstream>
#include <string>
#include "blockgenerator.h"

class Level0 : public BlockGenerator
{
		std::stringstream sequence;
	public:
		Level0(std::string& file);
		Block* makeBlock();
};

#endif