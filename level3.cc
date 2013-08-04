#include <cstdlib>
#include "level3.h"

Block* Level3::makeBlock()
{
	int num = rand() % 9;
	switch(num)
	{
		case 0:
			return new Block('I', 3);
		case 1:
			return new Block('J', 3);
		case 2:
			return new Block('L', 3);
		case 3:
			return new O(3);
		case 4:
		case 5:
			return new Block('S', 3);
		case 6:
			return new Block('T', 3);
		case 7:
		case 8:
			return new Block('Z', 3);
		default:
			return 0;
   }
}