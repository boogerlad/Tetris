/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Definitions for block class, a component of the Grid Class
*******************************************************************************/
#include "block.h"

Posn::Posn(int r, int c) : r(r), c(c){}

Posn operator+(const Posn a, const Posn b)
{
	return Posn(a.r + b.r, a.c + b.c);
}

void Block::swap(Block &b)
{
	Posn tempP = p;
	p = b.p;
	b.p = tempP;

	int tempNumRotations = numRotations;
	numRotations = b.numRotations;
	b.numRotations = tempNumRotations;

	int tempRotationIndex = rotationIndex;
	rotationIndex = b.rotationIndex;
	b.rotationIndex = tempRotationIndex;

	char tempType = type;
	type = b.type;
	b.type = tempType;

	int tempLevel = level;
	level = b.level;
	b.level = tempLevel;

	std::vector<Posn>* tempRotations = rotations;
	rotations = b.rotations;
	b.rotations = tempRotations;

	bool tempSet = set;
	set = b.set;
	b.set = tempSet;
}

Block::Block(Posn p, int numRotations, char type, int level)
	: p(p)
	, numRotations(numRotations)
	, rotationIndex(0)
	, type(type)
	, level(level)
	, rotations(new std::vector<Posn>[numRotations])
	, set(false)
{}

Block::Block(const Block& b)
	: p(b.p)
	, numRotations(b.numRotations)
	, rotationIndex(b.rotationIndex)
	, type(b.type)
	, level(b.level)
	, rotations(new std::vector<Posn>[numRotations])
	, set(b.set)
{
	for(int i = 0; i < numRotations; ++i)
	{
		for(std::vector<Posn>::iterator it = b.rotations[i].begin(); it != b.rotations[i].end(); ++it)
		{
			rotations[i].push_back(*it);
		}
	}
}

Block::~Block()
{
	delete[] rotations;
}

Block& Block::operator=(const Block &b)
{
	Block temp = b;
	swap(temp);
	return *this;
}

void Block::cw()
{
	if(!set)
	++rotationIndex &= (numRotations - 1);
}

void Block::ccw()
{
	if(!set)
	--rotationIndex &= (numRotations - 1);
}

void Block::left()
{
	if(!set)
	--p.c;
}

void Block::right()
{
	if(!set)
	++p.c;
}

void Block::down()
{
	if(!set)
	++p.r;
}

void Block::removeCells(int absRow)
{
	for(std::vector<Posn>::iterator it = rotations[rotationIndex].begin(); it != rotations[rotationIndex].end();)
	{
		if(absRow - p.r == it->r)
		{
			it = rotations[rotationIndex].erase(it);
		}
		else
		{
			if(absRow - p.r < it->r)
			{
				--it->r;
			}
			++it;
		}
	}
	++p.r;
}

int Block::getRotIdx() const
{
	return rotationIndex;
}

int Block::cwRotIdx() const
{
	return (rotationIndex + 1) & (numRotations - 1);
}

int Block::ccwRotIdx() const
{
	return (rotationIndex - 1) & (numRotations - 1);
}

const std::vector<Posn>& Block::getCells() const
{
	return rotations[rotationIndex];
}

const std::vector<Posn>& Block::getCells(int rotIdx) const
{
	return rotations[rotIdx];
}

Posn Block::getKey() const
{
	return p;
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
	return rotations[rotationIndex].size();
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
	for(int i = 0; i < b.getNumCells(); ++i)
	{
		Posn a = b.rotations[b.rotationIndex][i];
		preview[a.r][a.c] = b.type;
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