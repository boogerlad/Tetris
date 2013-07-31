/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the S class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "s.h"

S::S(int level) : Block::Block(Posn(2, 0), 2, 'S', level)
{
	rotations[0].push_back(Posn(1, 1));
	rotations[0].push_back(Posn(1, 2));
	rotations[0].push_back(Posn(2, 1));
	rotations[0].push_back(Posn(2, 0));

	rotations[1].push_back(Posn(0, 0));
	rotations[1].push_back(Posn(1, 0));
	rotations[1].push_back(Posn(1, 1));
	rotations[1].push_back(Posn(2, 1));
}

void S::cw()
{
	rotationIndex = !rotationIndex;
}

void S::ccw()
{
	S::cw();
}

int S::cwRotIdx() const
{
	return !rotationIndex;
}

int S::ccwRotIdx() const
{
	return S::cwRotIdx();
}
