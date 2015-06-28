#include <iostream>

#include "Map.h"
#include "Utils.h"
#include "PathFinder.h"

using namespace std;

int main() {

    Map* map = Utils::fileToMap("/Users/Philippe/Workspace/save-the-princess/sample_input.txt");
    PathFinder pathFinder = PathFinder(map);

    map->print();


    return 0;
}