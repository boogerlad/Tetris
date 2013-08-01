/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the Z class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "z.h"

Z::Z(int level) : Block::Block(Posn(3, 0), 'Z', level)
{
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(2, 1));
}