/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* definitions for the S class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "s.h"

S::S(int level) : Block::Block(Posn(3, 0), 'S', level)
{
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(1, 0));
	cells.push_back(Posn(2, 0));
}