#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

class GridProblem {
    std::vector<std::string> lines;
    int lineLength;
    int numLines;
    int numPoundHit;

public:
    GridProblem(const std::string&);   //take in input filename to store into lines
    void countPoundHits(int slopeX, int slopeY);
    bool poundHit(int posX, int posY);
    int getNumHits();
    void resetGrid();
    void doPartTwo();
};