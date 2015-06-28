#ifndef SAVE_THE_PRINCESS_MAP_H
#define SAVE_THE_PRINCESS_MAP_H

#include <vector>
#include <math.h>

using namespace std;

enum Tiles {
    GOAL = 'p',
    START = 'm',
    OBSTACLE = 'x',
    NOTHING = '-'
};

struct Node {
    short position;
    short value;
    bool opened;
    bool closed;
    int fScore;
    int gScore;
    int hScore;
    Node* parent;
};

class Map {

    vector<Node*> map;
    short size;
    Node* startNode;
    Node* endNode;

    bool isAvailable(short index);

public:
    Map(short size);

    void push(short value);
    short getSize();
    Node* getStartPosition();
    Node* getGoalPosition();
    Node* get(short index);
    Node* get(short x, short y);
    vector<Node*> getNeighbours(short position);
    void print();

};


#endif //SAVE_THE_PRINCESS_MAP_H
