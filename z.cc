/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the Z class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "z.h"

Z::Z(int level) : Block::Block(Posn(2, 0), 2, 'Z', level)
{
	rotations[0].push_back(Posn(1, 0));
	rotations[0].push_back(Posn(1, 1));
	rotations[0].push_back(Posn(2, 1));
	rotations[0].push_back(Posn(2, 2));

	rotations[1].push_back(Posn(0, 1));
	rotations[1].push_back(Posn(1, 1));
	rotations[1].push_back(Posn(1, 0));
	rotations[1].push_back(Posn(2, 0));
}

void Z::cw()
{
	rotationIndex = !rotationIndex;
}

void Z::ccw()
{
	Z::cw();
}

int Z::cwRotIdx() const
{
	return !rotationIndex;
}

int Z::ccwRotIdx() const
{
	return Z::cwRotIdx();
}