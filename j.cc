/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Constructor for the J class, subclass of Block
* All permutations of the relative positions of each cell
*******************************************************************************/
#include "j.h"

J::J(int level) : Block::Block(Posn(3, 0), 'J', level)
{
	cells.push_back(Posn(0, 0));
	cells.push_back(Posn(0, 1));
	cells.push_back(Posn(1, 1));
	cells.push_back(Posn(2, 1));
}