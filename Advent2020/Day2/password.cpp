#include "password.h"


void Password::set_num_one(std::ifstream& inFile) {
    inFile >> this->num_one;
}


void Password::set_num_two(std::ifstream& inFile) {
    inFile.ignore(1, '-');  //skip hyphen from input
    inFile >> this->num_two;
}


void Password::set_letter(std::ifstream& inFile) {
    inFile >> this->letter;
}


void Password::set_pw(std::ifstream& inFile) {
    inFile.ignore(2, ' ');  //ignore until letters appear from input
    std::getline(inFile, this->pw);
}

void Password::print_data() {
    std::cout << "num one: " << this->num_one << "\tnum two: " << this->num_two << "\tletter: " << this->letter << "\tpw: " << this->pw << std::endl;
}



bool Password::test_one() {

    int count = std::count(pw.begin(), pw.end(), letter);   //num occurences of letter

    //check if count is less than num_one or greater than num_two
    return (count >= num_one && count <= num_two) ? true : false;
}


bool Password::test_two() {
    std::cout << pw[num_one - 1] << "\t" << pw[num_two - 1] << std::endl;

    //index num_one - 1 must be letter, num_two - 1 must not be letter
   if (pw[num_one - 1] != letter) return false;
   else if (pw[num_two - 1] == letter) return false;
   else return true; 
}