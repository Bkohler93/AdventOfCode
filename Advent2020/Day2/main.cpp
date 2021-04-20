#include <iostream>
#include "password.h"
#include <fstream>


int main () {

    int part_one = 0;   //final count of valid pw part 1
    int part_two = 0;   //final count of valid pw part 2


    //create file stream and check if failed
    std::ifstream inFile("inputs.txt");
    if (inFile.fail()) {
        std::cerr << "failed to open file" << std::endl;
        return 0;
    }


    while (inFile.good()) {

        Password new_pw;

        new_pw.set_num_one(inFile);
        new_pw.set_num_two(inFile);
        new_pw.set_letter(inFile);
        new_pw.set_pw(inFile);

        //check password validity
        if (new_pw.test_one()) part_one++;
        
        if (new_pw.test_two()) part_two++;

        new_pw.print_data();
    }

    std::cout << "Part one has " << part_one << " valid passwords.\n";
    std::cout << "Part two has " << part_two << " valid passwords.\n";

 
    return 0;
}
