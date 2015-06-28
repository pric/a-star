#include <iostream>
#include "Map.h"

Map::Map(short size) {

    this->size = size;
}

void Map::push(short value){

    Node* node = new Node;
    node->position = (short)this->map.size();
    node->value = value;
    node->closed = false;
    node->opened = false;

    if (value == Tiles::START) {

        this->startNode = node;
    }

    if (value == Tiles::GOAL) {

        this->endNode = node;
    }

    this->map.push_back(node);
}

short Map::getSize() {

    return this->size;
}

Node* Map::getStartPosition() {

    return this->startNode;
}

Node* Map::getGoalPosition() {

    return this->endNode;
}

Node* Map::get(short index) {

    return this->map.at(index);
}

bool Map::isAvailable(short index) {

    return get(index)->value != Tiles::OBSTACLE;
}

vector<Node*> Map::getNeighbours(short position) {

    vector<Node*> neighbours;

    short north = position - this->size;
    short south = position + this->size;
    short west = position - 1;
    short east = position + 1;

    if (north >= 0 && isAvailable(north)) {

        neighbours.push_back(map.at(north));
    }

    if (south <= (pow(this->size,2) - 1)
        && isAvailable(south)) {

        neighbours.push_back(map.at(south));
    }

    if (west >=0 && floor(west/size) == floor(position/size)
        && isAvailable(west)) {

        neighbours.push_back(map.at(west));
    }

    if (east <= (pow(this->size,2) - 1)
        && floor(east/size) == floor(position/size)
        && isAvailable(east)) {

        neighbours.push_back(map.at(east));
    }

    return neighbours;
}

void Map::print() {

    for (int i = 0; i < pow(this->size,2); ++i) {

        std::cout << (char)this->get(i)->value << "(" << this->get(i)->position << "), ";

        if ((i+1)%this->size == 0){
            std::cout << endl;
        }
    }
}