const Cell = require("./lib/Cell.js");

const DIRECTION_TOP = "top";
const DIRECTION_RIGHT = "right";
const DIRECTION_BOTTOM = "bottom";
const DIRECTION_LEFT = "left";

const SPACE_STRING = " ";
const SPACE_BOOL = true;
const WALL_STRING = "#";
const WALL_BOOL = false;

module.exports = class MazeGenerator {
    constructor(width = 10, height = 10) {
        this.width = width;
        this.height = height;
        this.totalCellsCount = width * height;
        this.matrix = [];
        this.init();
    }
    init() {
        for (let y = 0; y < this.height; y++) {
            const line = [];
            for (let x = 0; x < this.width; x++) {
                line.push(new Cell(x, y));
            }
            this.matrix.push(line);
        }
    }
    draw(spaceString = SPACE_STRING, wallString = WALL_STRING) {
        const matrix = this.get();
        const string = matrix
            .map((line) => {
                return line
                    .map((value) => {
                        return value ? spaceString : wallString;
                    })
                    .join("");
            })
            .join("\n");
        console.log(string);
    }
    generate() {
        this.reset();

        let cell = this.getCell(Math.floor(Math.random() * this.width), Math.floor(Math.random() * this.height));
        let countVisited = 0;
        const stack = [];

        stack.push(cell);
        countVisited++;

        while (countVisited < this.totalCellsCount) {
            cell = stack[stack.length - 1];
            cell.isVisited = true;

            const neighbours = this.getNeighbours(cell);

            if (neighbours.length === 0) {
                stack.pop();
            } else {
                const index = Math.floor(Math.random() * neighbours.length);
                const neighbour = neighbours[index];
                const nextCell = neighbour.cell;

                switch (neighbour.direction) {
                    case DIRECTION_RIGHT:
                        cell.carveRight();
                        break;
                    case DIRECTION_BOTTOM:
                        cell.carveBottom();
                        break;
                    case DIRECTION_LEFT:
                        nextCell.carveRight();
                        break;
                    case DIRECTION_TOP:
                        nextCell.carveBottom();
                        break;
                }

                stack.push(nextCell);
                countVisited++;
            }
        }
    }
    get() {
        const matrix = [];
        const row0 = new Array(this.width * 2 + 1).fill(WALL_BOOL);
        matrix.push(row0);

        for (let y = 0; y < this.height; y++) {
            const line1 = [WALL_BOOL];
            const line2 = [WALL_BOOL];
            for (let x = 0; x < this.width; x++) {
                const cell = this.getCell(x, y);
                line1.push(SPACE_BOOL);
                line1.push(cell.hasRightWall ? WALL_BOOL : SPACE_BOOL);

                line2.push(cell.hasBottomWall ? WALL_BOOL : SPACE_BOOL);
                line2.push(WALL_BOOL);
            }
            matrix.push(line1);
            matrix.push(line2);
        }
        return matrix;
    }
    getCell(column, row) {
        return this.matrix[row][column];
    }
    getNeighbours(cell) {
        const neighbours = [];
        const x = cell.x;
        const y = cell.y;

        const pushNeighbour = (x, y, direction) => {
            const cell = this.getCell(x, y);
            if (!cell.isVisited) {
                neighbours.push({
                    cell: cell,
                    direction: direction,
                });
            }
        };

        if (x + 1 < this.width) {
            pushNeighbour(x + 1, y, DIRECTION_RIGHT);
        }
        if (x - 1 >= 0) {
            pushNeighbour(x - 1, y, DIRECTION_LEFT);
        }
        if (y + 1 < this.height) {
            pushNeighbour(x, y + 1, DIRECTION_BOTTOM);
        }
        if (y - 1 >= 0) {
            pushNeighbour(x, y - 1, DIRECTION_TOP);
        }

        return neighbours;
    }
    reset() {
        this.matrix = [];
        this.init();
    }
};
