#ifndef SAVE_THE_PRINCESS_UTILS_H
#define SAVE_THE_PRINCESS_UTILS_H

#include <string>
#include "Grid.h"

class Utils {

public:

    static Grid* fileToGrid(const std::string& fileName);

};


#endif //SAVE_THE_PRINCESS_UTILS_H
