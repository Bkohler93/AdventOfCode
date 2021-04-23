#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


class Password {
    int num_one;
    int num_two;
    char letter;
    std::string pw;

public:
    Password() : num_one(0), num_two(0), letter(0), pw("empty") {};
    void set_num_one(std::ifstream& inFile);
    void set_num_two(std::ifstream& inFile);
    void set_letter(std::ifstream& inFile);
    void set_pw(std::ifstream& inFile);
    void print_data();

    bool test_one();
    bool test_two();

};

#endif