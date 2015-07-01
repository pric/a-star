#include <iostream>

#include "Grid.h"
#include "Utils.h"
#include "PathFinder.h"

int main(int argc, char* argv[]) {

    clock_t tStart = clock();

    Grid* grid = Utils::fileToGrid(argv[1]);
    PathFinder pathFinder = PathFinder(grid);

    pathFinder.AStar(grid->getStartPosition(), grid->getGoalPosition());
    pathFinder.getInstructions();

    printf("Execution time: %.5f seconds\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}