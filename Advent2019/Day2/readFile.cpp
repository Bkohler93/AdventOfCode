#include "readFile.h"


void getInputs(const std::string& filename, std::vector<int> &prog)
{

	//create ifstream object
	std::ifstream inFile(filename);

	//create line to store each line from inFile
	std::string line;

	//loop until no more lines are taken into line from inFile
	while (std::getline(inFile, line))
	{
		//store line into a stringstream
		std::stringstream linestream(line);
	
		//new string var to store each new integer from file
		std::string val;

		//get each individual integer from stringstream
		while (std::getline(linestream, val, ','))
		{
			//fill in program array with each val in integer form
			prog.push_back(std::stoi(val));
		}

	}

}