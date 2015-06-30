#include <iostream>
#include "Grid.h"

Grid::Grid(unsigned long size) {

    m_size = size;
}

void Grid::push(const char value){

    Node* node = new Node;
    node->position = static_cast<int>(m_grid.size());
    node->value = value;
    node->closed = false;
    node->opened = false;

    if (value == TILE_START) {

        m_startNode = node;
    }

    if (value == TILE_GOAL) {

        m_endNode = node;
    }

    m_grid.push_back(node);
}

const std::size_t Grid::getSize() const {

    return m_size;
}

Node* Grid::getStartPosition() const {

    return m_startNode;
}

Node* Grid::getGoalPosition() const {

    return m_endNode;
}

Node* Grid::get(const unsigned int index) const {

    return m_grid[index];
}

void Grid::set(const unsigned int index, const char value) {

    m_grid[index]->value = value;
}

const bool Grid::isAvailable(const unsigned int index) const {

    return get(index)->value != TILE_OBSTACLE;
}

std::vector<Node*> Grid::getNeighbours(const unsigned int index) const {

    std::vector<Node*> neighbours;

    int north = static_cast<int>(index - m_size);
    int south = static_cast<int>(index + m_size);
    int west = index - 1;
    int east = index + 1;

    if (north >= 0 && isAvailable(north)) {

        neighbours.push_back(m_grid[north]);
    }

    if (south <= ((m_size * m_size) - 1)
        && isAvailable(south)) {

        neighbours.push_back(m_grid[south]);
    }

    if (west >=0 && floor(west/ m_size) == floor(index / m_size)
        && isAvailable(west)) {

        neighbours.push_back(m_grid[west]);
    }

    if (east <= ((m_size * m_size) - 1)
        && floor(east/ m_size) == floor(index / m_size)
        && isAvailable(east)) {

        neighbours.push_back(m_grid[east]);
    }

    return neighbours;
}

void Grid::print() {

    for (int i = 0; i < pow(m_size,2); ++i) {

        std::cout << get(i)->value;

        if ((i+1) % m_size == 0){
            std::cout << std::endl;
        }
    }
}