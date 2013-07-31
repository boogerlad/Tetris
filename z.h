#ifndef __Z_H__
#define __Z_H__

#include "block.h"

struct Z : public Block
{
	Z(int level);
	void cw();
	void ccw();
	int cwRotIdx() const;
	int ccwRotIdx() const;
};

#endif