#include "s.h"

S::S(int level) : Block::Block(Posn(3, 0), 'S', level)
{
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(2, 0));
}