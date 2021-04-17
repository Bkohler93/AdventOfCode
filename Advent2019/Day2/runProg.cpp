#include "runProg.h"


//performs operations throughout program input
void process_prog(int it, std::vector<int> &prog)
{
	//check if at 99 yet (basecase)
	if (prog[it] == 99 || it >= prog.size())
		return;

	//perform addition calculation if current prog[it] is 1
	else if (prog[it] == 1)
	{	
		//3 positions away from the 1, becomes addition of 1 and 2 positions away from 1
		prog[prog[it+3]] = prog[prog[it + 1]] + prog[prog[it + 2]];
	}

	//else current val must be a 2, perform multiplication
	else 
	{
		//same as previous but use multiplication on two elements from third away from 2
		prog[prog[it+3]] = prog[prog[it + 1]] * prog[prog[it + 2]];
	}

	//run proccess_prog again but with it + 4
	process_prog(it + 4, prog);
}


//find it ans is correct yet
bool findAns(std::vector<int> &prog, int val) {

	//process current prog and see if it equals value
	process_prog(0, prog);

	if (prog[0] == val) return true;

	return false;

}


//loops through every noun/val
void findNoun_Verb(std::vector<int> &prog, int& noun, int& verb) {

	//use copy because this will change everytime findAns is run
	std::vector<int> progCopy;

	//loop through nouns
	for (int i = 0; i < 99; i++) {

		
		//loop verbs
		for (int j = 0; j < 99; j++) {

			//set copy to prog
			progCopy = prog;

			progCopy[1] = i;
			progCopy[2] = j;

			//check if correct with current noun (i) and verb(j)
			if (findAns(progCopy, 19690720)) {
				noun = i;
				verb = j;
				return;
			}
		}
	}

	//if reached this point no noun/verbs reached output goal
	std::cout << "no answer found" << std::endl;
	return;
}