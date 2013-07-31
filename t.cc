/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Constructor for the J class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "t.h"

T::T(int level) : Block::Block(Posn(2, 0), 4, 'T', level)
{
	rotations[0].push_back(Posn(1, 0));
	rotations[0].push_back(Posn(1, 1));
	rotations[0].push_back(Posn(1, 2));
	rotations[0].push_back(Posn(2, 1));

	rotations[1].push_back(Posn(0, 1));
	rotations[1].push_back(Posn(1, 1));
	rotations[1].push_back(Posn(2, 1));
	rotations[1].push_back(Posn(1, 0));

	rotations[2].push_back(Posn(2, 0));
	rotations[2].push_back(Posn(2, 1));
	rotations[2].push_back(Posn(2, 2));
	rotations[2].push_back(Posn(1, 1));

	rotations[3].push_back(Posn(0, 0));
	rotations[3].push_back(Posn(1, 0));
	rotations[3].push_back(Posn(2, 0));
	rotations[3].push_back(Posn(1, 1));
}