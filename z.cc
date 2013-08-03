#include "z.h"

Z::Z(int level) : Block::Block(Posn(3, 0), 'Z', level)
{
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(2, 1));
}