#include "JgCell.h"
using namespace JagGame;
Cell::Cell() {}
Cell::Cell(int i, int j, int k) {
	x = i;
	y = j;
	z = k;
}

Cell::Cell(int i, int j) {
	x = i;
	y = j;
	z = 0;
}

Cell Cell::operator+(Cell c) {
	return Cell(x + c.x, y + c.y, z + c.z);
}

Cell Cell::operator-(Cell c) {
	return Cell(x - c.x, y - c.y, z - c.z);
}
