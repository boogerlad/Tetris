/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Definitions for the O class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "o.h"

O::O(int level) : Block::Block(Posn(3, 0), 1, 'O', level)
{
	rotations[0].push_back(Posn(0, 0));
	rotations[0].push_back(Posn(0, 1));
	rotations[0].push_back(Posn(1, 0));
	rotations[0].push_back(Posn(1, 1));
}

void O::cw(){}

void O::ccw(){}

int O::cwRotIdx() const
{
	return rotationIndex;
}

int O::ccwRotIdx() const
{
	return O::cwRotIdx();
}