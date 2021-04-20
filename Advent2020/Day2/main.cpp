#include "gridproblem.h"

int main () {

    GridProblem grid("inputs.txt");

    std::cout << "Part 1: "; grid.countPoundHits(3, 1);
    std::cout <<"--------------------------------\n";
    grid.resetGrid();

    grid.doPartTwo();

    return 0;
}