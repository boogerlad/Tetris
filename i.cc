#include "i.h"

I::I(int level) : Block::Block(Posn(3, 0), 'I', level)
{
	for(int i = 0; i < 4; ++i)
	{
		cells.push_back(Posn(i, 1));
	}
}