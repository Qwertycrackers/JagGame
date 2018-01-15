#ifndef __JGCELL__
namespace JagGame {
/*!\brief Struct Cell represents a point in 3d space.
*
* Intended for use in `TileDataEngine`s to represent a tile location. Has the `+` and `-` operators for convienience. */
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
