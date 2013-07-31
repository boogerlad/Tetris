/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Definitions for Level0 class, derived from Level Class
*******************************************************************************/
#include "level0.h"

Level0::Level0(std::string& file)
{
	std::ifstream ifile(file.c_str());
	sequence << ifile.rdbuf();
	ifile.close();
}

Block* Level0::makeBlock()
{
	char c;
   if (sequence.eof()) { return NULL; }

	sequence >> c;

	{
		switch(c)
		{
			case 'I':
				return new I(0);
			case 'J':
				return new J(0);
			case 'L':
				return new L(0);
			case 'O':
				return new O(0);
			case 'S':
				return new S(0);
			case 'Z':
				return new Z(0);
			case 'T':
				return new T(0);
			default:
				return 0;
		}
	}
}
