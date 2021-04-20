#include "funcs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() {

    std::map<int, int> num_map;

    //PART ONE////

    //get ifstream from inputs.txt
    std::ifstream inFile = get_inputs("inputs.txt");

    //create var for new nums
    int num;

    while (inFile) {
        
        inFile >> num;
        
        //if current num is found in map, that means it's value is
        //value that sums to 2020
        if (num_map[num]) {
            std::cout << "nums are: " << num << " and " << num_map[num] << ".\nAnswer is: " << num * num_map[num] << ".\n";
        }        

        //use int that would sum with num to 2020 as key, and num as it's value
        else {
            num_map[2020 - num] = num;
        }
    }    
    


    std::cout << "-----------------------------\n";



    //PART TWO
    inFile.clear();
    inFile = get_inputs("inputs.txt");


    //create vector to store all ints
    std::vector<int> nums;
    int new_num;

    while (inFile) {

        inFile >> new_num;
        nums.push_back(new_num);        
    }

    int size = nums.size();

    //loop through each number once
    for (int i = 0; i < size - 2; i++) {

        //create a map like in first part
        std::map<int, std::vector<int>> num_map;

        //loop through each number nested
        for (int j = i + 1; j < size; j++) {

            //if a key already exists for j'th integer, that means our answer has been found
            if (num_map.find(nums[j]) != num_map.end()) {
                std::cout << "Nums are " << num_map[nums[j]][0] << " " << num_map[nums[j]][1] << " " << nums[j] << std::endl;
                std::cout << "Answer is: " << num_map[nums[j]][0] *  num_map[nums[j]][1] *  nums[j] << std::endl;
            }

            //if a key with the j'th number doesn't exist, create a new key with the number needed to make i'th + j'th + new = 2020
            //and fill the values with a vector of the i'th and j'th integer to keep a record of these two numbers.
            else {
                num_map[2020 - nums[i] - nums[j]].push_back(nums[i]);
                num_map[2020 - nums[i] - nums[j]].push_back(nums[j]);
            }
        }
    }
    return 0;
}