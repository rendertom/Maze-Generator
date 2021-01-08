# Maze-Generator

A customisable maze generator for C++ and JavaScript.

```javascript
##########################################
##  ##                  ##              ##
##  ##  ##########  ######  ##########  ##
##  ##  ##      ##  ##      ##      ##  ##
##  ##  ######  ##  ##  ######  ##  ##  ##
##  ##          ##  ##          ##  ##  ##
##  ##########  ##  ##########  ######  ##
##          ##  ##  ##      ##  ##      ##
##  ######  ##  ##  ##  ##  ##  ##  ######
##      ##  ##  ##      ##      ##      ##
######  ##  ##  ######################  ##
##      ##  ##          ##  ##          ##
##  ##################  ##  ##  ##########
##                          ##          ##
##  ##################################  ##
##      ##  ##                  ##      ##
######  ##  ##  ##############  ##  ##  ##
##      ##  ##      ##      ##  ##  ##  ##
##  ######  ######  ##  ##  ##  ##  ##  ##
##          ##      ##  ##          ##  ##
##########################################
```

## Requirements

- for c++
  - gcc compiler
  - c++ 2011 standard (`-std=c++11`)
- for javascript
  - [Node](https://nodejs.org/en/)

## How to use it

1. Include MazeGenerator in your main application

    ```javascript
    // c++:
    #include "../MazeGenerator.cpp"

    // javascript:
    const MazeGenerator = require("../MazeGenerator.js");
    ```

2. Define variables

    ```javascript
    // c++:
    MazeGenerator maze;
    // or
    // MazeGenerator maze(x, y);
    MazeGenerator maze(20, 10);

    // javascript:
    const maze = new MazeGenerator();
    // or
    // const maze = new MazeGenerator(x, y);
    const maze = new MazeGenerator(20, 10);

    // where 'x' is the width of the maze and 'x' is the height;
    ```

3. Generate a maze

    ```javascript
    // c++ and javascript
    maze.generate();
    ```

4. Draw maze in console

    ```javascript
    // c++ and javascript
    maze.draw();

    // or
    // maze.draw(spaceString, wallString);
    maze.draw("  ", "##");
    ```

5. Result:

    ```javascript
    ##################################################################################
    ##                  ##          ##          ##                                  ##
    ##  ##  ##  ##########  ##  ######  ##  ######  ##################  ##########  ##
    ##  ##  ##  ##          ##          ##          ##          ##  ##          ##  ##
    ##  ##  ######  ######################################  ##  ##  ######  ######  ##
    ##  ##  ##      ##          ##                          ##  ##  ##  ##  ##      ##
    ##  ##  ##  ##########  ##  ######  ##############  ##########  ##  ##  ##  ######
    ##  ##  ##          ##  ##      ##              ##  ##          ##      ##      ##
    ######  ##########  ##  ######  ##  ##########  ######  ##########  ##########  ##
    ##      ##      ##      ##      ##          ##      ##          ##          ##  ##
    ##  ##  ##  ##  ##########  ##########  ##########  ##########  ##############  ##
    ##  ##  ##  ##  ##      ##          ##  ##                  ##      ##      ##  ##
    ##  ##  ##  ##  ######  ##########  ######  ##############  ######  ##  ##  ##  ##
    ##  ##      ##          ##      ##      ##      ##  ##      ##  ##  ##  ##  ##  ##
    ##  ##################  ##  ##  ######  ##  ##  ##  ##  ######  ##  ##  ##  ##  ##
    ##      ##      ##      ##  ##  ##      ##  ##  ##  ##          ##      ##  ##  ##
    ##  ##  ##  ##  ##########  ##  ##  ##########  ##  ##########  ##########  ##  ##
    ##  ##      ##              ##  ##  ##      ##  ##              ##      ##  ##  ##
    ##  ##########################  ##  ##  ##  ##  ##  ##################  ##  ##  ##
    ##                          ##          ##      ##                      ##      ##
    ##################################################################################
    ```

6. Get a 2D `bool` array representing `spaces` and `walls`

    ```javascript
    // c++:
    vector < vector < bool >> matrix = maze.get();

    // javascript:
    const matrix = maze.get();
    ```

## Demo

How to run `demo` files:

```javascript
// c++:
cd c++/demo
g++ -std=c++11 'demo.cpp' -o 'demo' && './demo'

// javascript
cd js/demo
node demo.js
```

### Inspiration

- [Mazes with Blockwise Geometry](https://weblog.jamisbuck.org/2015/10/31/mazes-blockwise-geometry.html)
- [Programming Mazes](https://www.youtube.com/watch?v=Y37-gB83HKE)