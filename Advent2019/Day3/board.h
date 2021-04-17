#ifndef BOARD_H
#define BOARD_H

#include "point.h"
#include <sstream>
#include <string>
#include <iostream>

class Board {
private:

	Point* wire_1;
	Point* wire_2;
	int min_dist;	//minimum distance from origin to intersection point:
	int min_steps;

	//create static vars to store steps taken
	static int steps_wire_1;
	static int steps_wire_2;

public:

	//constructors
	Board() : wire_1(nullptr), wire_2(nullptr), min_dist(999999999), min_steps(1000000) {}

	//destructor
	~Board();
	void del_wire_1(Point* wire_1_copy);

	void fill_wire_1(std::stringstream &wire_1_stream);
	void fill_wire_2(std::stringstream &wire_1_stream);

	//get closest intersection distance
	int get_min_inters() {return min_dist;}

	//check if wires intersect one another
	bool check_cross(int x, int y);
	void check_coords_wire_1(Point* &copy_wire1, bool& crossed, int x, int y);

	int check_min(int, int);
};

#endif