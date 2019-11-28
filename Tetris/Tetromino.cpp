#include "Tetromino.h"


Tetromino::Tetromino() {
	//color;
	//shape;
	//blockLocs;
	setShape(TetShape::SHAPE_T);
};

void Tetromino::setShape(TetShape newShape) {
	shape = newShape;								// set the shape
	blockLocs.clear();
	switch (shape) {
	case TetShape::SHAPE_S: //complete
		color = TetColor::RED;
		blockLocs.push_back(Point(-1,0));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(1,1));
		break;
	case TetShape::SHAPE_Z:  //complete
		color = TetColor::GREEN;
		blockLocs.push_back(Point(-1,1));
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(1,0));
		break;
	case TetShape::SHAPE_L: //complete
		color = TetColor::ORANGE;
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,-1));
		blockLocs.push_back(Point(1,-1));
		break;
	case TetShape::SHAPE_J:
		color = TetColor::BLUE_DARK;
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,-1));
		blockLocs.push_back(Point(-1,-1));
		break;
	case TetShape::SHAPE_O: //complete
		color = TetColor::YELLOW;
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(1,1));
		blockLocs.push_back(Point(1,0));
		break;
	case TetShape::SHAPE_I: // complete
		color = TetColor::BLUE_LIGHT;
		blockLocs.push_back(Point(0,2));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,1));
		blockLocs.push_back(Point(0,-1));
		break;
	case TetShape::SHAPE_T: //complete
		color = TetColor::PURPLE;
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,-1));
		blockLocs.push_back(Point(-1,0));
		blockLocs.push_back(Point(1,0));
		break;
	default:
		color = TetColor::RED; // complete
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,0));
		blockLocs.push_back(Point(0,0));
		break;
	}
}

static TetShape getRandomShape() { return static_cast<TetShape>(rand() % static_cast<int>(TetShape::SHAPE_COUNT)); }

void Tetromino::rotateCW() {
	for (int i = 0; i<blockLocs.size(); i++) {
		blockLocs[i].swapXY();
		blockLocs[i].multiplyY(-1);
	}
}

void Tetromino::printToConsole() const {
	for (int y = 3; y >= -3; y--) {
		for (int x = -3; x <= 3; x++) {

			bool found{ false };
			for (int k = 0; k < blockLocs.size(); k++) {
				if (blockLocs[k].getX() == x && blockLocs[k].getY() == y) {
					found = true;
				}
				
			}
			if (found) {
				std::cout << "x";
			}
			else {
				std::cout << "-";
			}


		}
		std::cout << '\n';
	}
	std::cout << '\n';
};	