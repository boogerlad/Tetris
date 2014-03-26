#include <string>
#include "grid.h"

void Grid::drawBlock(Block& b)
{
	for(std::vector<Posn>::const_iterator it = b.getCells().begin(); it != b.getCells().end(); ++it)
	{
		Posn absPosn = b.getGhost() + *it;
		cells[absPosn.y][absPosn.x] = ghost;
		absPosn = b.getKey() + *it;
		cells[absPosn.y][absPosn.x] = b.getType();
	}

}

void Grid::clearBlock(Block& b)
{
	b.ghostSet = false;
	for(std::vector<Posn>::const_iterator it = b.getCells().begin(); it != b.getCells().end(); ++it)
	{
		Posn absPosn = b.getGhost() + *it;
		cells[absPosn.y][absPosn.x] = empty;
		absPosn = b.getKey() + *it;
		cells[absPosn.y][absPosn.x] = empty;
	}
}

bool Grid::testCollision(bool down)
{
	if(currentBlock->set)
	{
		return true;
	}
	for(std::vector<Posn>::const_iterator it = currentBlock->getCells().begin(); it != currentBlock->getCells().end(); ++it)
	{
		Posn absPosn = currentBlock->getKey() + *it;
		if(absPosn.x < 0 || absPosn.x >= maxX)
		{
			return true;
		}
		else if(absPosn.y < 0 || absPosn.y >= maxY)
		{
			currentBlock->set = true;
			canHold = true;
			blocksOnGrid.push_back(currentBlock);
			return true;
		}
		else if(cells[absPosn.y][absPosn.x] != empty)// && cells[absPosn.y][absPosn.x] != ghost
		{
			if(down)
			{
				currentBlock->set = true;
				canHold = true;
				blocksOnGrid.push_back(currentBlock);
			}
			return true;
		}
	}
	return false;
}

bool Grid::ghostCollision()
{
	for(std::vector<Posn>::const_iterator it = currentBlock->getCells().begin(); it != currentBlock->getCells().end(); ++it)
	{
		Posn absPosn = currentBlock->getGhost() + *it;
		if(absPosn.y >= maxY || cells[absPosn.y][absPosn.x] != empty)
		{
			currentBlock->ghostSet = true;
			return true;
		}
	}
	return false;
}

Grid::Grid(int level, std::string file)
	: level(level)
	, gen(Level::makeBlockGenerator(level, file))
	, scoreboard(new Scoreboard())
	, currentBlock(0)
	, nextBlock(gen->makeBlock())
	, holdBlock(0)
	, canHold(true)
{
	resetGrid();
}

Grid::~Grid()
{
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
	for(int i = 0; i < maxY; ++i)
	{
		for(int j = 0; j < maxX; ++j)
		{
			cells[i][j] = empty;
		}
	}
}

void Grid::reset()
{
	resetGrid();
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
	if(!currentBlock || Grid::testCollision())
	{
		return false;
	}
	else
	{
		while(!currentBlock->ghostSet)
		{
			currentBlock->downGhost();
			if(Grid::ghostCollision())
			{
				currentBlock->upGhost();
			}
		}
		drawBlock(*currentBlock);
		return true;
	}
}

void Grid::cw()
{
	clearBlock(*currentBlock);
	currentBlock->cw();
	if(Grid::testCollision())
	{
		currentBlock->ccw();
	}
	currentBlock->updateGhost();
	Grid::dropGhost();
	drawBlock(*currentBlock);
}

void Grid::ccw()
{
	clearBlock(*currentBlock);
	currentBlock->ccw();
	if(Grid::testCollision())
	{
		currentBlock->cw();
	}
	currentBlock->updateGhost();
	Grid::dropGhost();
	drawBlock(*currentBlock);
}

void Grid::down()
{
	clearBlock(*currentBlock);
	currentBlock->down();
	if(Grid::testCollision(true))
	{
		currentBlock->up();
	}
	currentBlock->updateGhost();
	Grid::dropGhost();
	drawBlock(*currentBlock);
}

void Grid::drop()
{
	clearBlock(*currentBlock);
	while(!currentBlock->set)
	{
		currentBlock->down();
		if(Grid::testCollision(true))
		{
			currentBlock->up();
		}
	}
	currentBlock->updateGhost();
	drawBlock(*currentBlock);
}

void Grid::dropGhost()
{
	while(!currentBlock->ghostSet)
	{
		currentBlock->downGhost();
		if(Grid::ghostCollision())
		{
			currentBlock->upGhost();
		}
	}
}

void Grid::left()
{
	clearBlock(*currentBlock);
	currentBlock->left();
	if(Grid::testCollision())
	{
		currentBlock->right();
	}
	currentBlock->updateGhost();
	Grid::dropGhost();
	drawBlock(*currentBlock);
}

void Grid::right()
{
	clearBlock(*currentBlock);
	currentBlock->right();
	if(Grid::testCollision())
	{
		currentBlock->left();
	}
	currentBlock->updateGhost();
	Grid::dropGhost();
	drawBlock(*currentBlock);
}

void Grid::hold()
{
	if(canHold)
	{
		char temp = holdBlock;
		holdBlock = currentBlock->getType();
		clearBlock(*currentBlock);
		delete currentBlock;
		if(temp)
		{
			currentBlock = new Block(temp, level);
			while(!currentBlock->ghostSet)
			{
				currentBlock->downGhost();
				if(Grid::ghostCollision())
				{
					currentBlock->upGhost();
				}
			}
			drawBlock(*currentBlock);
		}
		else
		{
			Grid::place();
		}
		canHold = false;
	}
}

void Grid::clearLines()
{
	int numLinesCleared = 0;
	for(int i = 0; i < maxY; ++i)
	{
		bool filled = true;
		for(int j = 0; j < maxX; ++j)
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
		   		(*it)->updateGhost();
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
	out << "HighScore:   " << g.scoreboard->getHighScore() << std::endl;
	out << "Hold:        " << g.holdBlock << std::endl;
	out << "----------" << std::endl;
	for(int i = invisibleBuffer; i < maxY; ++i)
	{
		for(int j = 0; j < maxX; ++j)
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
	}
	return out;
}
