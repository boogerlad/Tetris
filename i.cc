/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the I class, child of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "i.h"

I::I(int level) : Block::Block(Posn(0, 0), 2, 'I', level)
{
	for(int i = 0; i < 4; ++i)
	{
		rotations[0].push_back(Posn(3, i));
		rotations[1].push_back(Posn(i, 0));
	}
}

void I::cw()
{
	rotationIndex = !rotationIndex;
}

void I::ccw()
{
	I::cw();
}

int I::cwRotIdx() const
{
	return !rotationIndex;
}

int I::ccwRotIdx() const
{
	return I::cwRotIdx();
}
