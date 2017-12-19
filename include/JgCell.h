#ifndef __JGCELL__
namespace JagGame {
struct Cell {
	int x;
	int y;
	int z;
	Cell();
	Cell(int,int,int);
	Cell(int,int);
	Cell operator+(Cell);
	Cell operator-(Cell);
};
} //namespace JagGame
#define __JGCELL__
#endif
