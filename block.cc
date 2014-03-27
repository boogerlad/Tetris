#include "block.h"

Posn::Posn(int x, int y) : x(x), y(y) {}

Posn operator+(const Posn a, const Posn b)
{
	return Posn(a.x + b.x, a.y + b.y);
}

Block::Block(char type, int level)
	: p(Posn(3, 0))
	, ghost(p)
	, type(type)
	, level(level)
	, set(false)
	, ghostSet(false)
{
	switch(type)
	{
		case 'I':
			cells.push_back(Posn(0, 1));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(2, 1));
			cells.push_back(Posn(3, 1));
			break;
		case 'J':
			cells.push_back(Posn(0, 0));
			cells.push_back(Posn(0, 1));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(2, 1));
			break;
		case 'L':
			cells.push_back(Posn(0, 1));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(2, 1));
			cells.push_back(Posn(2, 0));
			break;
		case 'S':
			cells.push_back(Posn(0, 1));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(1, 0));
			cells.push_back(Posn(2, 0));
			break;
		case 'T':
			cells.push_back(Posn(0, 1));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(1, 0));
			cells.push_back(Posn(2, 1));
			break;
		case 'Z':
			cells.push_back(Posn(0, 0));
			cells.push_back(Posn(1, 0));
			cells.push_back(Posn(1, 1));
			cells.push_back(Posn(2, 1));
			break;
	}
}

void Block::cw()
{
	for(std::vector<Posn>::iterator it = cells.begin(); it != cells.end(); ++it)
	{
		int tempX = it->x;
		it->x = 2 - it->y;
		it->y = tempX;
	}
}

void Block::ccw()
{
	for(std::vector<Posn>::iterator it = cells.begin(); it != cells.end(); ++it)
	{
		int tempX = it->x;
		it->x = it->y;
		it->y = 2 - tempX;
	}
}

void Block::left()
{
	--p.x;
}

void Block::right()
{
	++p.x;
}

void Block::up()
{
	--p.y;
}

void Block::down()
{
	++p.y;
}

void Block::upGhost()
{
	--ghost.y;
}

void Block::downGhost()
{
	++ghost.y;
}

void Block::removeCells(int absY)
{
	for(std::vector<Posn>::iterator it = cells.begin(); it != cells.end();)
	{
		if(absY - p.y == it->y)
		{
			it = cells.erase(it);
		}
		else
		{
			if(absY - p.y < it->y)
			{
				--it->y;
			}
			++it;
		}
	}
	++p.y;
}

const std::vector<Posn>& Block::getCells() const
{
	return cells;
}

Posn Block::getKey() const
{
	return p;
}

Posn Block::getGhost() const
{
	return ghost;
}

char Block::getType() const
{
	return type;
}

int Block::getLevel() const
{
	return level;
}

int Block::getNumCells() const
{
	return cells.size();
}

std::ostream& operator<<(std::ostream &out, const Block& b)
{
	char preview[4][4];
	//every block at most is 4x4
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			preview[i][j] = ' ';
		}
	}
	for(std::vector<Posn>::const_iterator it = b.getCells().begin(); it != b.getCells().end(); ++it)
	{
		preview[it->y][it->x] = b.getType();
	}
	for(int i = 0; i < 4; ++i)
	{
		bool empty = true;
		for(int j = 0; j < 4; ++j)
		{
			if(preview[i][j] != ' ')
			{
				empty = false;
				break;
			}
		}
		if(!empty)
		{
			for(int j = 0; j < 4; ++j)
			{
				out << preview[i][j];
			}
			if(i != 3)
			{
				out << std::endl;
			}
		}
	}
	return out;
}

void Block::updateGhost()
{
	ghost = p;
}