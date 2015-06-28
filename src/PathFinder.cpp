#include <list>
#include "PathFinder.h"

using namespace std;

PathFinder::PathFinder(Map* gameMap) {

    this->gameMap = gameMap;
}

short PathFinder::getHeuristic(short first, short second) {

    short mapSize = this->gameMap->getSize();
    short first_x = (short)floor(first / mapSize);
    short first_y = first % mapSize;
    short second_x = (short)floor(second / mapSize);
    short second_y = second / mapSize;

    return (short)sqrt(pow((second_x-first_x),2) + pow((second_y-first_y),2));
}

void PathFinder::AStar(Node* start, Node* end) {



}