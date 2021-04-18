#include "funcs.h"
#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {

    std::map<int, int> num_map;

    //get ifstream from inputs.txt
    std::ifstream inFile = get_inputs("inputs.txt");

    //create var for new nums
    int num;

    //PART ONE
    while (inFile) {
        
        inFile >> num;
        
        //if current num is found in map, that means it's value is
        //value that sums to 2020
        if (num_map[num]) {
            std::cout << "nums are: " << num << " and " << num_map[num] << ".\nMultipied together: " << num * num_map[num] << ".\n";
        }        

        //use int that would sum with num to 2020 as key, and num as it's value
        else {
            num_map[2020 - num] = num;
        }
    }    
    
    //PART TWO
    inFile.clear();
    inFile = get_inputs("inputs.txt");

    // //fill in tree, find two whose sum is 2020
    // BST tree;

    // //get first val from inFile
    // int val;
    // inFile >> val;

    // //fill in tree
    // tree.fill_tree(val, inFile, tree.get_root());

    // //find two nums whose sum is 2020
    // tree.find_two_sum();

    // std::cout << "done" << std::endl;
    return 0;
}