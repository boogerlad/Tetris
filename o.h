#ifndef __O_H__
#define __O_H__

#include "block.h"

struct O : public Block
{
	O(int level);
	void cw() {}
	void ccw() {}
};

#endif