#include "Utils.h"

using namespace std;

Map* Utils::fileToMap(string fileName) {

    char ch;
    Map* map;
    fstream fin(fileName, fstream::in);

    string firstLine;

    getline(fin, firstLine);

    map = new Map(atoi(firstLine.c_str()));

    while (fin >> noskipws >> ch) {

        if(ch != '\n') {

            map->push(ch);
        }
    }

    return map;
}