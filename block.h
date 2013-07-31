#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <ostream>
#include <vector>


struct Posn
{
	int r, c;
	Posn(int r = 0, int c = 0);
};

Posn operator+(const Posn a, const Posn b);

class Block
{
	protected:
		Posn p;
		int numRotations;
		int rotationIndex;
		char type;
		int level;
		void swap(Block &b);
		std::vector<Posn>* rotations;//[numRotations][4 cells]
	public:
		bool set;
		Block(Posn p, int numRotations, char type, int level);
		Block(const Block& b);
		virtual ~Block();
		Block& operator=(const Block& b);

		virtual void cw();
		virtual void ccw();
		void left();
		void right();
		void down();
		void removeCells(int absRow);

		int getRotIdx() const;
		virtual int cwRotIdx() const;
		virtual int ccwRotIdx() const;
		const std::vector<Posn>& getCells() const;
		const std::vector<Posn>& getCells(int rotIdx) const;
		Posn getKey() const;
		char getType() const;
		int getLevel() const;
		int getNumCells() const;

		friend std::ostream& operator<<(std::ostream &out, const Block& b);
};

std::ostream& operator<<(std::ostream &out, const Block& b);

#endif