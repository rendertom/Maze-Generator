#include <iostream>
class Cell {
   public:
    int x;
    int y;
    bool hasBottomWall = true;
    bool hasRightWall = true;
    bool isVisited = false;
	std::string direction = "";

    Cell(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void carveBottom();
    void carveRight();
    void print();
};

void Cell::carveBottom() {
    hasBottomWall = false;
}

void Cell::carveRight() {
    hasRightWall = false;
}

void Cell::print() {
    std::cout << "Cell: ";
    std::cout << "x: " << x << ", ";
    std::cout << "y: " << y << ", ";
    std::cout << "hasBottomWall: " << hasBottomWall << ", ";
    std::cout << "hasRightWall: " << hasRightWall << ", ";
    std::cout << "isVisited: " << isVisited << ", ";
	std::cout << "direction: " << direction << std::endl;
}