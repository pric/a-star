#ifndef SAVE_THE_PRINCESS_PATHFINDER_H
#define SAVE_THE_PRINCESS_PATHFINDER_H

#include "Grid.h"

static const char* DIRECTION_UP = "UP";
static const char* DIRECTION_DOWN = "DOWN";
static const char* DIRECTION_LEFT = "LEFT";
static const char* DIRECTION_RIGHT = "RIGHT";

class PathFinder {

    Grid* m_grid;
    Node* m_endPoint;
    bool m_solutionFound;

    unsigned int getHeuristic(const Node* first, const Node* second);

public:
    PathFinder(Grid* grid);
    void AStar(Node* start, Node* end);
    void getInstructions();
    void drawSolution();

};


#endif //SAVE_THE_PRINCESS_PATHFINDER_H
