/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Definitions for the O class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "o.h"

O::O(int level) : Block::Block(Posn(4, 0), 'O', level)
{
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
}