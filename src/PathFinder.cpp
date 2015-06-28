#include <list>
#include <stack>
#include <iostream>
#include "PathFinder.h"

using namespace std;

PathFinder::PathFinder(Map* gameMap) {

    this->gameMap = gameMap;
    this->solutionFound = false;
}

int PathFinder::getHeuristic(Node* first, Node* second) {

    short mapSize = this->gameMap->getSize();
    short first_x = (short)floor(first->position / mapSize);
    short first_y = first->position % mapSize;
    short second_x = (short)floor(second->position / mapSize);
    short second_y = second->position / mapSize;

    return (int)(sqrt(pow((second_x-first_x),2) + pow((second_y-first_y),2)) *10);
}

void PathFinder::renderSolution(){

    stack<string> directives;
    Node* current;

    if (this->solutionFound){

        while (current->parent != nullptr) {

            short diff = current->parent->position - current->position;

            if(diff == 1){

                directives.push("LEFT");
            } else if (diff == -1){

                directives.push("RIGHT");
            } else if (diff == gameMap->getSize()) {

                directives.push("UP");
            } else if (diff == -gameMap->getSize()) {

                directives.push("DOWN");
            }

            current = current->parent;
        }

        while (!directives.empty()){

            cout << directives.top() << endl;
            directives.pop();
        }

    } else {

        cout << "No solution found" << endl;
    }

}

void PathFinder::AStar(Node* start, Node* end) {

    Node* current;

    list<Node*> openList;
    list<Node*> closedList;
    list<Node*>::iterator i;

    unsigned int iterationCount = 0;

    openList.push_back(start);
    start->opened = true;

    while ((iterationCount == 0 || (current != end)) && iterationCount < pow(gameMap->getSize(),2)) {

        for (i = openList.begin(); i != openList.end(); ++ i) {

            if (i == openList.begin() || (*i)->fScore <= current->fScore) {

                current = *i;
            }
        }

        if (current == end) {

            this->solutionFound = true;
            break;
        }

        openList.remove(current);
        closedList.push_back(current);

        current->opened = false;
        current->closed = true;

        vector<Node*> neighbours = this->gameMap->getNeighbours(current->position);

        for ( Node* child : neighbours) {

            if (child->closed) {

                continue;
            }

            if (child->opened) {

                if(child->gScore >= (current->gScore + 10)){

                    child->parent = current;
                    child->gScore = current->gScore + 10;
                    child->hScore = this->getHeuristic(child, end);
                    child->fScore = child->gScore + child->hScore;
                }

            } else {

                openList.push_back(child);
                child->opened = true;
                child->parent = current;
                child->gScore = current->gScore + 10;
                child->hScore = this->getHeuristic(child, end);
                child->fScore = child->gScore + child->hScore;
            }
        }

        ++iterationCount;
    }

    this->endPoint = current;
}