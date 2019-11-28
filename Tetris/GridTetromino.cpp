// The GridTetromino extends the basic Tetromino
// Functionality added:
//  - The concept of the tetromino's location on the gameboard/grid. (gridLoc)
//  - The ability to change a tetromino's location
//  - The ability to retrieve a vector of tetromino block locations mapped to the gridLoc.
//
//  [expected .cpp size: ~ 40 lines]

#include "GridTetromino.h"

// constructor, initialize gridLoc to 0,0
GridTetromino::GridTetromino() { gridLoc.setXY(0, 0); }

// return the tetromino's grid/gameboard loc (x,y)
Point GridTetromino::getGridLoc() const { return gridLoc; }

// sets the tetromino's grid/gameboard loc using x,y
void GridTetromino::setGridLoc(int x, int y) { gridLoc.setXY(x, y); }

// sets the tetromino's grid/gameboard loc using a Point
void GridTetromino::setGridLoc(const Point& pt) { gridLoc.setXY(pt.getX() ,pt.getY()); }

// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)
void GridTetromino::move(int xOffset, int yOffset) {
	gridLoc.setXY(gridLoc.getX() + xOffset, gridLoc.getY() + yOffset);
}

// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	std::vector<Point> blockLocsOnGrid;
	for (auto &p : blockLocs) {
		blockLocsOnGrid.push_back(Point(p.getX()+gridLoc.getX(), p.getY()+gridLoc.getY()));
	}
	return blockLocsOnGrid;
}