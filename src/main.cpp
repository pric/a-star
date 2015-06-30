#include <iostream>

#include "Grid.h"
#include "Utils.h"
#include "PathFinder.h"

int main(int argc, char* argv[]) {

    Grid* grid = Utils::fileToGrid(argv[1]);
    PathFinder pathFinder = PathFinder(grid);

    pathFinder.AStar(grid->getStartPosition(), grid->getGoalPosition());
    pathFinder.getInstructions();

    return 0;
}