#include <iostream>

#include "Map.h"
#include "Utils.h"

using namespace std;

int main() {

    Map* map = Utils::fileToMap("/Users/Philippe/Workspace/save-the-princess/sample_input.txt");

    map->print();

    return 0;
}