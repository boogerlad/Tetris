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
	switch(c)
	{
		case 'I':
		case 'J':
		case 'L':
		case 'S':
		case 'T':
		case 'Z':
			return new Block(c, 0);
		case 'O':
			return new O(0);
		default:
			return 0;
	}
}