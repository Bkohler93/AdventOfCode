
#include "funcs.h"

std::ifstream get_inputs(std::string fileName) {
    
    //create file stream
    std::ifstream inFile("inputs.txt");

    //check if worked
    assert(inFile); 

    return inFile;
}