#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__
#include "block.h"

class Scoreboard
{
		int highScore;
		int score;
	public:
		void lineScore(int level, int lines);
		void blockScore(const Block& b);
		void resetScore();
		int getScore();
		int getHighScore();
};

#endif