#ifndef SAVE_THE_PRINCESS_UTILS_H
#define SAVE_THE_PRINCESS_UTILS_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include "Map.h"

class Utils {

public:

    static Map* fileToMap(string fileName);

};


#endif //SAVE_THE_PRINCESS_UTILS_H
