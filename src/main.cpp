#include <iostream>

#include "Map.h"
#include "Utils.h"
#include "PathFinder.h"

using namespace std;

int main(int argc, char* argv[]) {

    Map* map = Utils::fileToMap(argv[1]);
    PathFinder pathFinder = PathFinder(map);

    pathFinder.AStar(map->getStartPosition(), map->getGoalPosition());
    pathFinder.renderSolution();


    return 0;
}