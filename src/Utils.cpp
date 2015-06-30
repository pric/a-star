#include <fstream>
#include "Utils.h"

Grid* Utils::fileToGrid(const std::string& fileName) {

    char ch;
    Grid* grid;
    std::fstream fin(fileName, std::fstream::in);

    std::string firstLine;

    getline(fin, firstLine);

    grid = new Grid(atoi(firstLine.c_str()));

    while (fin >> std::noskipws >> ch) {

        if(ch != '\n') {

            grid->push(ch);
        }
    }

    return grid;
}