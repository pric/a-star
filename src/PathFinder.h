#ifndef SAVE_THE_PRINCESS_PATHFINDER_H
#define SAVE_THE_PRINCESS_PATHFINDER_H

#include "Map.h"

class PathFinder {

    Map* gameMap;

    short getHeuristic(short first, short second);

public:
    PathFinder(Map* map);
    void AStar(short start, short end);

};


#endif //SAVE_THE_PRINCESS_PATHFINDER_H
