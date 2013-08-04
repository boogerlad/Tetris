#include <cstdlib>
#include "level1.h"

Block* Level1::makeBlock()
{
	int num = rand() % 12;
	switch(num)
	{
		case 0:
		case 1:
			return new Block('I', 1);
		case 2:
		case 3:
			return new Block('J', 1);
		case 4:
		case 5:
			return new Block('L', 1);
		case 6:
		case 7:
			return new O(1);
		case 8:
			return new Block('S', 1);
		case 9:
		case 10:
			return new Block('T', 1);
		case 11:
			return new Block('Z', 1);
		default:
			return 0;
	}
}