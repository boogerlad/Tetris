#include "l.h"

L::L(int level) : Block::Block(Posn(3, 0), 'L', level)
{
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(2, 1));
	cells.push_back(Posn(2, 0));
}