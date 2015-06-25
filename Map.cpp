#include <iostream>
#include "Map.h"

Map::Map(unsigned short size) {

    this->size = size;
}

void Map::push(unsigned short value){

    this->map.push_back(value);
}

unsigned short Map::get(unsigned short index) {

    return this->map.at(index);
}

unsigned short Map::get(unsigned short x, unsigned short y) {

    return this->map.at(this->size*x + y);
}

void Map::print() {

    for (int i = 0; i < pow(this->size,2); ++i) {

        std::cout << this->get(i) << ", ";

        if ((i+1)%this->size == 0){
            std::cout << endl;
        }
    }
}