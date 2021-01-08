#include <iostream>
#include <stack>
#include <vector>

#include "./lib/Cell.cpp"

using namespace std;

#define DIRECTION_TOP "top"
#define DIRECTION_RIGHT "right"
#define DIRECTION_BOTTOM "bottom"
#define DIRECTION_LEFT "left"

#define SPACE_STRING " "
#define SPACE_BOOL true
#define WALL_STRING "#"
#define WALL_BOOL false

class MazeGenerator {
   public:
    int width;
    int height;
    int totalCellsCount;
    vector<vector<Cell>> matrix;

    MazeGenerator(int width = 10, int height = 10) {
        this->width = width;
        this->height = height;
        this->totalCellsCount = width * height;
        this->init();

        srand(time(NULL));
    }

    void draw(string spaceString = SPACE_STRING, string wallString = WALL_STRING) {
        vector<vector<bool>> matrix = get();
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[y].size(); x++) {
                cout << (matrix[y][x] ? spaceString : wallString);
            }
            cout << endl;
        }
    }

    void generate() {
        reset();

        int countVisited = 0;
        int neighbourIndex;
        Cell *cell = getCell(rand() % width, rand() % height);
        Cell *nextCell;
        stack<Cell *> stack;
        string direction;
        vector<Neighbour> neighbours;
        Neighbour neighbour;

        stack.push(cell);
        countVisited++;

        while (countVisited < totalCellsCount) {
            cell = stack.top();
            cell->isVisited = true;

            neighbours = getNeighbours(cell);

            if (neighbours.size() == 0) {
                stack.pop();
            } else {
                neighbourIndex = rand() % neighbours.size();
                neighbour = neighbours[neighbourIndex];
                nextCell = neighbour.cell;
                direction = neighbour.direction;

                if (direction == DIRECTION_RIGHT) {
                    cell->carveRight();
                } else if (direction == DIRECTION_BOTTOM) {
                    cell->carveBottom();
                } else if (direction == DIRECTION_LEFT) {
                    nextCell->carveRight();
                } else if (direction == DIRECTION_TOP) {
                    nextCell->carveBottom();
                }

                stack.push(nextCell);
                countVisited++;
            }
        }
    }

    vector<vector<bool>> get() {
        Cell *cell;
        vector<vector<bool>> matrix;
        vector<bool> row0(width * 2 + 1, WALL_BOOL);
        vector<bool> row1;
        vector<bool> row2;

        matrix.push_back(row0);
        for (int y = 0; y < height; y++) {
            row1 = {WALL_BOOL};
            row2 = {WALL_BOOL};

            for (int x = 0; x < width; x++) {
                cell = getCell(x, y);
                row1.push_back(SPACE_BOOL);
                row1.push_back(cell->hasRightWall ? WALL_BOOL : SPACE_BOOL);

                row2.push_back(cell->hasBottomWall ? WALL_BOOL : SPACE_BOOL);
                row2.push_back(WALL_BOOL);
            }
            matrix.push_back(row1);
            matrix.push_back(row2);
        }
        return matrix;
    }

   private:
    struct Neighbour {
        Cell *cell;
        string direction;
    };

    void fillNeighbour(int x, int y, string direction, vector<Neighbour> *neighbours) {
        Cell *cell = getCell(x, y);
        if (!cell->isVisited) {
            Neighbour neighbour = {
                .cell = cell,
                .direction = direction,
            };
            neighbours->push_back(neighbour);
        }
    }

    vector<Neighbour> getNeighbours(Cell *cell) {
        const int x = cell->x;
        const int y = cell->y;
        vector<Neighbour> neighbours;

        if (x + 1 < width) {
            fillNeighbour(x + 1, y, DIRECTION_RIGHT, &neighbours);
        }
        if (x - 1 >= 0) {
            fillNeighbour(x - 1, y, DIRECTION_LEFT, &neighbours);
        }
        if (y + 1 < height) {
            fillNeighbour(x, y + 1, DIRECTION_BOTTOM, &neighbours);
        }
        if (y - 1 >= 0) {
            fillNeighbour(x, y - 1, DIRECTION_TOP, &neighbours);
        }
        return neighbours;
    }

    Cell *getCell(int column, int row) {
        return &matrix[row][column];
    }

    void init() {
        for (int y = 0; y < height; y++) {
            vector<Cell> row;

            for (int x = 0; x < width; x++) {
                Cell cell(x, y);
                row.push_back(cell);
            }
            matrix.push_back(row);
        }
    }

    void printCells() {
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[y].size(); x++) {
                matrix[y][x].print();
            }
        }
    }

    void reset() {
        matrix.clear();
        matrix.resize(0);
        init();
    }
};
