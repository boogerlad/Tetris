#include "blockgenerator.h"

Block* BlockGenerator::makeBlock(char type, int level)
{
	switch(type)
	{
		case 'I':
			return new I(level);
		case 'J':
			return new J(level);
		case 'L':
			return new L(level);
		case 'O':
			return new O(level);
		case 'S':
			return new S(level);
		case 'Z':
			return new Z(level);
		case 'T':
			return new T(level);
		default:
			return 0;
	}
}