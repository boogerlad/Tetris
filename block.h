#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <ostream>
#include <vector>

struct Posn
{
	int x, y;
	Posn(int x = 0, int y = 0);
};

Posn operator+(const Posn a, const Posn b);

class Block
{
	protected:
		Posn p;
		char type;
		int level;
		std::vector<Posn> cells;
	public:
		bool set;
		Block(Posn p, char type, int level);
		virtual ~Block() {}

		virtual void cw();
		virtual void ccw();
		void left();
		void right();
		void up();
		void down();
		void removeCells(int absY);

		const std::vector<Posn>& getCells() const;
		Posn getKey() const;
		char getType() const;
		int getLevel() const;
		int getNumCells() const;
};

std::ostream& operator<<(std::ostream &out, const Block& b);

#endif