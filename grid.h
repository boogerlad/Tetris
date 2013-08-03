#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include "scoreboard.h"
#include "level.h"
#include "blockgenerator.h"

const int maxX = 10;
const int maxY = 22;
const int invisibleBuffer = 2;
const char empty = ' ';

class Grid
{
		int level;
		char cells[maxY][maxX];
		BlockGenerator* gen;
		Scoreboard* scoreboard;
		Block* currentBlock;
		Block* nextBlock;
		Block* ghostBlock;
		char holdBlock;
		bool canHold;
		std::vector<Block*> blocksOnGrid;
		void drawBlock(Block& b);
		void clearBlock(Block& b);
		bool testCollision(bool down = false);
		void resetGrid();
	public:
		Grid(int level, std::string file);
		~Grid();

		void reset();

		bool place();
		void cw();
		void ccw();
	 	void drop();
	 	void down();
	 	void left();
		void right();
		void hold();

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
