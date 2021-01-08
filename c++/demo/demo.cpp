/*
    Maze Generator
    Developed by Tomas Šinkūnas, 2021-01-08
    www.rendertom.com
    Repository: https://github.com/rendertom/Maze-Generator

    API:
    void generate()                 - Generates new maze layout.
    void draw([string spaceString], [string wallString]) - Prints maze into console.
        spaceString                 - Optional. Uses " " if not defined.
        wallString                  - Optional. Uses "#" if not defined.
    vector<vector<bool>> get()      - Returns maze as a 2D array, where 0 is "passage" and "1" is a wall.
*/

#include "../MazeGenerator.cpp"

int main() {
    MazeGenerator maze;

    maze.generate();
    maze.draw("  ", "##");
    maze.generate();
    maze.draw("11", "00");

    return 0;
}