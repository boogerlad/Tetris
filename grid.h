#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include "scoreboard.h"
#include "level.h"

const int maxRows = 18;
const int maxCols = 10;
const int invisibleBuffer = 3;
const char empty = ' ';

class Grid
{
		int level;
		char** cells;
		BlockGenerator* gen;
		Scoreboard* scoreboard;
		Block* currentBlock;
		Block* nextBlock;
		std::vector<Block*> blocksOnGrid;
		void drawBlock(Block& b);
		void clearBlock(Block& b);
		bool testCollision(int r, int c, int rotIdx);
	public:
		Grid(int level, std::string file);
		~Grid();

		void resetGrid();

		bool place();
		void cw();
		void ccw();
	 	void drop();
	 	void down();
	 	void left();
		void right();

		void clearLines();

		bool getCurrSet() const;
		Block* getNextBlock() const;

		int getLevel() const;
		void setLevel(int lvl);
		void setLevel(int lvl, std::string file);
		friend std::ostream& operator<<(std::ostream &out, const Grid &g);
};

std::ostream& operator<<(std::ostream &out, const Grid &g);

#endif
