#include <list>
#include <stack>
#include <iostream>
#include <vector>
#include "PathFinder.h"

PathFinder::PathFinder(Grid* grid) {

    m_grid = grid;
    m_solutionFound = false;
}

unsigned int PathFinder::getHeuristic(const Node* first, const Node* second) {

    std::size_t gridSize = m_grid->getSize();
    double first_x = floor(first->position / gridSize);
    double first_y = first->position % gridSize;
    double second_x = floor(second->position / gridSize);
    double second_y = second->position / gridSize;

    double delta_x = (second_x-first_x);
    double delta_y = (second_y-first_y);

    return static_cast<unsigned int>((sqrt(delta_x * delta_x + delta_y * delta_y) * 10));
}

void PathFinder::drawSolution(){

    Node* current = m_endPoint;

    while (current->parent != nullptr) {

        m_grid->set(current->position, TILE_PATH);
        current = current->parent;
    }

    m_grid->print();
}

void PathFinder::getInstructions(){

    std::stack<std::string> directives;
    Node* current = m_endPoint;

    if (m_solutionFound){

        while (current->parent != nullptr) {

            int diff = current->parent->position - current->position;

            if(diff == 1){

                directives.push(DIRECTION_LEFT);
            } else if (diff == -1){

                directives.push(DIRECTION_RIGHT);
            } else if (diff == m_grid->getSize()) {

                directives.push(DIRECTION_UP);
            } else if (diff == -m_grid->getSize()) {

                directives.push(DIRECTION_DOWN);
            }

            current = current->parent;
        }

        while (!directives.empty()){

            std::cout << directives.top() << std::endl;
            directives.pop();
        }

    } else {

        std::cout << "No solution found" << std::endl;
    }

}

void PathFinder::AStar(Node* start, Node* end) {

    Node* current;

    std::list<Node*> openList;
    std::list<Node*> closedList;
    std::list<Node*>::iterator i;

    unsigned int iterationCount = 0;

    openList.push_back(start);
    start->opened = true;

    while ((iterationCount == 0 || (current != end)) && iterationCount < pow(m_grid->getSize(),2)) {

        for (i = openList.begin(); i != openList.end(); ++ i) {

            if (i == openList.begin() || (*i)->fScore <= current->fScore) {

                current = *i;
            }
        }

        if (current == end) {

            m_solutionFound = true;
            break;
        }

        openList.remove(current);
        closedList.push_back(current);

        current->opened = false;
        current->closed = true;

        std::vector<Node*> neighbours = m_grid->getNeighbours(current->position);

        for ( auto child : neighbours) {

            if (child->closed) {

                continue;
            }

            if (child->opened) {

                if(child->gScore >= (current->gScore + 10)){

                    child->parent = current;
                    child->gScore = current->gScore + 10;
                    child->hScore = getHeuristic(child, end);
                    child->fScore = child->gScore + child->hScore;
                }

            } else {

                openList.push_back(child);
                child->opened = true;
                child->parent = current;
                child->gScore = current->gScore + 10;
                child->hScore = getHeuristic(child, end);
                child->fScore = child->gScore + child->hScore;
            }
        }

        ++iterationCount;
    }

    m_endPoint = current;
}