#ifndef SAVE_THE_PRINCESS_GRID_H
#define SAVE_THE_PRINCESS_GRID_H

#include <vector>
#include <cmath>

static const char TILE_GOAL = 'p';
static const char TILE_START = 'm';
static const char TILE_OBSTACLE = 'x';
static const char TILE_EMPTY = '-';
static const char TILE_PATH = 'o';

struct Node {
    unsigned int position;
    char value;
    bool opened;
    bool closed;
    int fScore;
    int gScore;
    int hScore;
    Node* parent;
};

class Grid {

    std::vector<Node*> m_grid;
    std::size_t m_size;
    Node* m_startNode;
    Node* m_endNode;

    const bool isAvailable(const unsigned int index) const;

public:
    Grid(unsigned long size);

    void push(const char value);
    const std::size_t getSize() const;
    Node* getStartPosition() const;
    Node* getGoalPosition() const;
    Node* get(const unsigned int index) const;
    void set(const unsigned int index, const char value);
    std::vector<Node*> getNeighbours(const unsigned int index) const;
    void print();

};

#endif //SAVE_THE_PRINCESS_GRID_H
