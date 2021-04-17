#include "board.h"
#include <fstream>
#include <iostream>

int main()
{
	//create file stream
	std::ifstream inFile("inputs.txt");

	//there will be two lines to get. 
	std::string wire_1, wire_2;

	//fill in first wire, into a string stream
	std::getline(inFile, wire_1);
	std::stringstream wire_1_stream;
	wire_1_stream << wire_1;

	//fill in second wire into stringstream
	std::getline(inFile, wire_2);
	std::stringstream wire_2_stream;
	wire_2_stream << wire_2;

	//create board object
	Board wires;


	//fill board with both wires
	wires.fill_wire_1(wire_1_stream);
	wires.fill_wire_2(wire_2_stream);


	//return minimum distance of a wire intersection and wire origins
	std::cout << "The smallest distance between an intersection of wires and the origin is " <<  wires.get_min_inters() << std::endl;

	return 0;
}