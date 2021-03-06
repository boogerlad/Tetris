#include "level.h"

BlockGenerator* Level::makeBlockGenerator(int level, std::string file)
{
	switch(level)
	{
		case 0:
			return new Level0(file);
		case 1:
			return new Level1();
		case 2:
			return new Level2();
		case 3:
			return new Level3();
		default:
			return 0;
	}
}