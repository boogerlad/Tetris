#include "scoreboard.h"

void Scoreboard::lineScore(int level, int lines)
{
	if(lines)
	{
		score += (level + lines) * (level + lines);
 		if (score > highScore)
		{
			highScore = score;
		}
	}
}

void Scoreboard::blockScore(const Block& b)
{
	score += (b.getLevel() + 1) * (b.getLevel() + 1);
	if (score > highScore)
	{
		highScore = score;
	}
}

void Scoreboard::resetScore()
{
	score = 0;
}

int Scoreboard::getScore()
{
	return score;
}

int Scoreboard::getHighScore()
{
	return highScore;
}
