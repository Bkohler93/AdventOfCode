#include "gridproblem.h"

int main () {

    GridProblem grid("inputs.txt");
    grid.countPoundHits(3, 1);

    std::cout << "Part 1: " <<  grid.getNumHits() << std::endl;
    std::cout <<"--------------------------------\n";
    grid.resetGrid();

    grid.doPartTwo();

    return 0;
}