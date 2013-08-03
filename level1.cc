#include <cstdlib>
#include "level1.h"

Block* Level1::makeBlock()
{
	int num = rand() % 12;
	switch(num)
	{
		case 0:
		case 1:
			return new I(1);
		case 2:
		case 3:
			return new J(1);
		case 4:
		case 5:
			return new L(1);
		case 6:
		case 7:
			return new O(1);
		case 8:
			return new S(1);
		case 9:
			return new Z(1);
		case 10:
		case 11:
			return new T(1);
		default:
			return 0;
	}
}
