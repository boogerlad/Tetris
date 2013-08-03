#include "t.h"

T::T(int level) : Block::Block(Posn(3, 0), 'T', level)
{
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(2, 1));
}