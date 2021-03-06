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
		Posn ghost;
		char type;
		int level;
		std::vector<Posn> cells;
	public:
		bool set;
		bool ghostSet;
		//make the bools private. set can't be unset, so need setter (one thing only) and getter
		Block(char type, int level);
		virtual ~Block() {}

		virtual void cw();
		virtual void ccw();
		void left();
		void right();
		void up();
		void down();
		void upGhost();
		void downGhost();
		void removeCells(int absY);

		const std::vector<Posn>& getCells() const;
		Posn getKey() const;
		Posn getGhost() const;
		char getType() const;
		int getLevel() const;
		int getNumCells() const;
		
		void updateGhost();
};

std::ostream& operator<<(std::ostream &out, const Block& b);

#endif