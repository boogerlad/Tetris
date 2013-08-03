#include "o.h"

O::O(int level) : Block::Block(Posn(4, 0), 'O', level)
{
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
}