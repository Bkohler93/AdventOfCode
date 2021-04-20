#ifndef GRIDPROBLEM_H
#define GRIDPROBLEM_H

#include "gridproblem.h"

GridProblem::GridProblem(const std::string &filename) : numLines(0), numPoundHit(0) {

    std::ifstream inFile(filename);
    assert(inFile.good());

    std::string newLine;
    while (inFile.good()) {
        std::getline(inFile, newLine);
        lines.push_back(newLine);
        numLines++;
    }
    lineLength = newLine.length(); //all lines are same length
}


void GridProblem::countPoundHits(int slopeX, int slopeY) {

    int posX = 0;
    int posY = 0;

    while (posY < numLines) {
        
        //move x direction
        if (posX + slopeX >= lineLength) {
            int tilEnd = lineLength - posX;
            posX = 0 + slopeX - tilEnd;
        } else {
            posX += slopeX;
        }

        //move y direction 
        posY += slopeY;

        //check if at end and 
        if (posY >= numLines) break;
        else if (poundHit(posX, posY)) {
            numPoundHit++;
        }
    
    }
}


bool GridProblem::poundHit(int posX, int posY) {
    return lines[posY][posX] == '#';
}


int GridProblem::getNumHits() {
    return this->numPoundHit;
}

void GridProblem::resetGrid() {
    numPoundHit = 0;
}

void GridProblem::doPartTwo() {
    int solution = 1;

    //first slope
    countPoundHits(1, 1);
    solution *= getNumHits();
    resetGrid();

    //second slope
    countPoundHits(3, 1);
    solution *= getNumHits();
    resetGrid();

    //third slope
    countPoundHits(5, 1);
    solution *= getNumHits();
    resetGrid();

    //fourth slope
    countPoundHits(7, 1);
    solution *= getNumHits();
    resetGrid();

    //fifth slope
    countPoundHits(1, 2);
    solution *= getNumHits();
    resetGrid();

    //print out solution
    std::cout << "Part 2 answer is " << solution << std::endl;
}

#endif