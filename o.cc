#include "o.h"

O::O(int level) : Block::Block('O', level)
{
	p = Posn(4, 0);
	ghost = p;
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
}