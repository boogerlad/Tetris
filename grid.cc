/*******************************************************************************
* Quadris/textris
* CS 246 Assignment 5 By Max Duan & Kevin Hua
*
*
* Definitions for Grid class
*******************************************************************************/
#include <string>
#include "grid.h"

void Grid::drawBlock(Block& b)
{
	for(std::vector<Posn>::const_iterator it = b.getCells().begin(); it != b.getCells().end(); ++it)
	{
		Posn absPosn = b.getKey() + *it;
		cells[absPosn.r][absPosn.c] = b.getType();
	}

}

void Grid::clearBlock(Block& b)
{
	for(std::vector<Posn>::const_iterator it = b.getCells().begin(); it != b.getCells().end(); ++it)
	{
		Posn absPosn = b.getKey() + *it;
		cells[absPosn.r][absPosn.c] = empty;
	}
}

bool Grid::testCollision(int r, int c, int rotIdx)
{
	if(currentBlock->set)
	{
		return true;
	}
	for(std::vector<Posn>::const_iterator it = currentBlock->getCells(rotIdx).begin(); it != currentBlock->getCells(rotIdx).end(); ++it)
	{
		Posn absPosn = currentBlock->getKey() + *it;
		if(absPosn.c + c < 0 || absPosn.c + c >= maxCols)
		{
			return true;
		}
		else if(absPosn.r + r < 0 || absPosn.r + r >= maxRows)
		{
			currentBlock->set = true;
			blocksOnGrid.push_back(currentBlock);
			return true;
		}
		else if(cells[absPosn.r + r][absPosn.c + c] != empty)
		{
			if(r)
			{
				currentBlock->set = true;
				blocksOnGrid.push_back(currentBlock);
			}
			return true;
		}
	}
	return false;
}

Grid::Grid(int level, std::string file)
	: level(level)
	, cells(new char*[maxRows])
	, gen(Level::makeBlockGenerator(level, file))
	, scoreboard(new Scoreboard())
	, currentBlock(0)
	, nextBlock(gen->makeBlock())
{
	for(int i = 0; i < maxRows; ++i)
	{
		cells[i] = new char[maxCols];
		for(int j = 0; j < maxCols; ++j)
		{
			cells[i][j] = empty;
		}
	}
}

Grid::~Grid()
{
	for(int i = 0; i < maxRows; ++i)
	{

		delete[] cells[i];
	}
	delete[] cells;
	delete currentBlock;
	delete nextBlock;
	for(std::vector<Block*>::iterator it = blocksOnGrid.begin(); it != blocksOnGrid.end(); ++it)
	{
		delete *it;
	}
	delete gen;
	delete scoreboard;
}

void Grid::resetGrid()
{
	for(int i = 0; i < maxRows; ++i)
	{
		for(int j = 0; j < maxCols; ++j)
		{
			cells[i][j] = empty;
		}
	}
	for(std::vector<Block*>::iterator it = blocksOnGrid.begin(); it != blocksOnGrid.end();)
	{
		delete *it;
		it = blocksOnGrid.erase(it);
	}
	delete currentBlock;
	delete nextBlock;
	nextBlock = gen->makeBlock();
	scoreboard->resetScore();
}

bool Grid::place()
{
	currentBlock = nextBlock;
	nextBlock = gen->makeBlock();
	if (currentBlock == NULL ) { return false; }
	if(Grid::testCollision(0, 0, currentBlock->getRotIdx()))
	{
		return false;
	}
	else
	{
		drawBlock(*currentBlock);
		return true;
	}
}

void Grid::cw()
{
	clearBlock(*currentBlock);
	if(!Grid::testCollision(0, 0, currentBlock->cwRotIdx()))
	{
		currentBlock->cw();
	}
	drawBlock(*currentBlock);
}

void Grid::ccw()
{
	clearBlock(*currentBlock);
	if(!Grid::testCollision(0, 0, currentBlock->ccwRotIdx()))
	{
		currentBlock->ccw();
	}
	drawBlock(*currentBlock);
}

void Grid::down()
{
	clearBlock(*currentBlock);
	if(!Grid::testCollision(1, 0, currentBlock->getRotIdx()))
	{
		currentBlock->down();
	}
	drawBlock(*currentBlock);
}

void Grid::drop()
{
	while(!currentBlock->set)
	{
		Grid::down();
	}
}

void Grid::left()
{
	clearBlock(*currentBlock);
	if(!Grid::testCollision(0, -1, currentBlock->getRotIdx()))
	{
		currentBlock->left();
	}
	drawBlock(*currentBlock);
}

void Grid::right()
{
	clearBlock(*currentBlock);
	if(!Grid::testCollision(0, 1, currentBlock->getRotIdx()))
	{
		currentBlock->right();
	}
	drawBlock(*currentBlock);
}

void Grid::clearLines()
{
	int numLinesCleared = 0;
	for(int i = 0; i < maxRows; ++i)
	{
		bool filled = true;
		for(int j = 0; j < maxCols; ++j)
		{
			if(cells[i][j] == empty)
			{
				filled = false;
				break;
			}
		}
		if(filled)
		{
			for(std::vector<Block*>::iterator it = blocksOnGrid.begin(); it != blocksOnGrid.end();)
			{
		   		clearBlock(*(*it));
		   		(*it)->removeCells(i);
				if(!(*it)->getNumCells())
				{
					scoreboard->blockScore(*(*it));
					//it is a pointer to a block pointer
					//*it is a block pointer
					//*it->getKey() deferences the block pointer and calls the function
					delete *it;
					it = blocksOnGrid.erase(it);
				}
				else
				{
					drawBlock(*(*it));
					++it;
				}
			}
			++numLinesCleared;
		}
	}
	scoreboard->lineScore(level, numLinesCleared);
}

bool Grid::getCurrSet() const
{
	return currentBlock->set;
}

Block* Grid::getNextBlock() const
{
	return nextBlock;
}

int Grid::getLevel() const
{
	return level;
}

void Grid::setLevel(int lvl)
{
	delete gen;
	level = lvl;
	gen = Level::makeBlockGenerator(level);
}

void Grid::setLevel(int lvl, std::string file)
{
   delete gen;
   level = lvl;
   gen = Level::makeBlockGenerator(level, file);
}

std::ostream& operator<<(std::ostream &out, const Grid& g)
{
	out << "Level:       " << g.getLevel() << std::endl;
	out << "Score:       " << g.scoreboard->getScore() << std::endl;
	out << "HighScore:   "    << g.scoreboard->getHighScore() << std::endl;
	out << "----------" << std::endl;
	for(int i = invisibleBuffer; i < maxRows; ++i)
	{
		for(int j = 0; j < maxCols; ++j)
		{
			out << g.cells[i][j];
		}
		out << std::endl;
	}
	out << "----------" << std::endl;
	out << "Next:" << std::endl;
	if(g.getNextBlock())
	{
	   out << *g.getNextBlock();
		out << std::endl;
	}
	return out;
}