#ifndef __I_H__
#define __I_H__

#include "block.h"

struct I : public Block
{
	I(int level);
	void cw();
	void ccw();
	int cwRotIdx() const;
	int ccwRotIdx() const;
};

#endif