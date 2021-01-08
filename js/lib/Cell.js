module.exports = class Cell {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.hasBottomWall = true;
        this.hasRightWall = true;
        this.isVisited = false;
    }
    carveBottom() {
        this.hasBottomWall = false;
    }
    carveRight() {
        this.hasRightWall = false;
    }
};
