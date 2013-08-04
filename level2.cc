#include <cstdlib>
#include "level2.h"

Block* Level2::makeBlock()
{
	int num = rand() % 7;
	switch(num)
	{
		case 0:
			return new Block('I', 2);
		case 1:
			return new Block('J', 2);
		case 2:
			return new Block('L', 2);
		case 3:
			return new O(2);
		case 4:
			return new Block('S', 2);
		case 5:
			return new Block('T', 2);
		case 6:
			return new Block('Z', 2);
		default:
			return 0;
	}
}