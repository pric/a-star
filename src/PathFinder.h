#ifndef SAVE_THE_PRINCESS_PATHFINDER_H
#define SAVE_THE_PRINCESS_PATHFINDER_H

#include "Map.h"

class PathFinder {

    Map* gameMap;
    Node* endPoint;
    bool solutionFound;

    int getHeuristic(Node* first, Node* second);

public:
    PathFinder(Map* map);
    void AStar(Node* start, Node* end);
    void renderSolution();

};


#endif //SAVE_THE_PRINCESS_PATHFINDER_H
