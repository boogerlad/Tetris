#ifndef __S_H__
#define __S_H__

#include "block.h"

struct S : public Block
{
	S(int level);
	void cw();
	void ccw();
	int cwRotIdx() const;
	int ccwRotIdx() const;
};

#endif