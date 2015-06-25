#ifndef SAVE_THE_PRINCESS_MAP_H
#define SAVE_THE_PRINCESS_MAP_H

#include <vector>
#include <math.h>

using namespace std;

enum Tiles {
    PRINCESS = 'p',
    KNIGHT = 'm',
    OBSTACLE = 'x',
    NOTHING = '-'
};

class Map {

vector<unsigned short> map;
unsigned short size;

public:
    Map(unsigned short size);

    void push(unsigned short value);
    unsigned short get(unsigned short index);
    unsigned short get(unsigned short x, unsigned short y);
    void print();

};


#endif //SAVE_THE_PRINCESS_MAP_H
