#include "readFile.h"
#include "runProg.h"
#include <vector>
#include <iostream>

int main()
{

	//create program code, going to be stored as vector of ints
	std::vector<int> prog;
	
	//fill in integers into prog from inputs text file
	getInputs("inputs.txt", prog);	


	//begin by setting pos 1 to 12 and pos 2 to 2 as per instructions
	prog[1] = 12;
	prog[2] = 2;
	
	//PART 1 performed with copy of prog
	std::vector<int> progCopy = prog;
	process_prog(0, progCopy);
	std::cout << "Part 1: value at position 0 is " << progCopy[0] << std::endl;


	//PART 2
	int noun;	//position 1 in program
	int verb;	//position 2 in program

	//solves for the correct noun/verb to result in goal output
	findNoun_Verb(prog, noun, verb);	

	//print results
	std::cout << "Part 2: Find noun (value at position 1) and verb (value at position 2) that produce\n an output of '100* noun + verb = 19690720'\n\n";
	std::cout << "noun is " << noun << " and verb is " << verb << std::endl;
	std::cout << "and answer is " << 100 * noun + verb << std::endl;

	return 0;
}