/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the I class, child of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "i.h"

I::I(int level) : Block::Block(Posn(3, 0), 'I', level)
{
	for(int i = 0; i < 4; ++i)
	{
		cells.push_back(Posn(i, 1));
	}
}